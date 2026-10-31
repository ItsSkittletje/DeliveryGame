# Technical Architecture

Living document. Updated whenever a system is added or changed.

## Toolchain (verified 2026-10-31)

| Tool | Version |
|------|---------|
| Unreal Engine | 5.8.4 (Launcher build, CL 58902052) — `C:\Program Files\Epic Games\UE_5.8` |
| Compiler | MSVC 14.44.35207 (VS 2022 Community, v143) — UE 5.8 minimum is 14.38 |
| Windows SDK | 10.0.22621.0 (used), 10.0.26100.0 (installed) |
| Editor | VS Code + Microsoft C/C++ extension pack (IntelliSense via UBT-generated compile commands) |
| VCS | Git 2.56 + Git LFS (`.uasset`/`.umap` are LFS + lockable) |

## Build commands

```powershell
# Compile editor module (close the editor first, or use Live Coding inside it: Ctrl+Alt+F11)
& "C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat" DeliveryGameEditor Win64 Development "-Project=$PWD\DeliveryGame.uproject" -WaitMutex

# Regenerate VS Code project files (after adding/removing source files)
& "C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\Build.bat" -projectfiles "-project=$PWD\DeliveryGame.uproject" -game -VSCode
```

## Module layout

Single runtime module `DeliveryGame`. Subsystem folders are created only when they get their first class.
The module directory is a public include path, so includes are written as `"Player/DGCharacter.h"`.

```
Source/DeliveryGame/
  DeliveryGame.h/.cpp        Module + LogDeliveryGame category
  Core/                      Session framework
    DGGameMode               Server-only rules; sets default classes
    DGGameState              Replicated session state (empty until M4/M5)
    DGPlayerState            Replicated per-player state (empty until needed)
  Player/
    DGPlayerController       Adds the input mapping context for the local player only
    DGCharacter              First-person pawn: capsule, camera, move + look
    DGInputSettings          Project Settings page pointing C++ at input assets
```

Class prefix `DG` (Delivery Game) avoids collisions with engine/plugin types.

## Multiplayer stance (from day one)

- Server-authoritative. `ADGGameMode` only exists on the server; anything that decides outcomes lives there or in server-side subsystems.
- `ADGGameState` / `ADGPlayerState` are the replicated carriers for shared and per-player state.
- Movement uses `UCharacterMovementComponent` (built-in client prediction + server reconciliation).
- Input is local-only: `ADGPlayerController::BeginPlay` returns early for non-local controllers, so the same code runs correctly on a listen server, dedicated server and clients.
- A dedicated `Server` target needs a source-built engine; add `DeliveryGameServer.Target.cs` when we move to source (Milestone 6 decision).

## Input (Enhanced Input)

Assets live in `Content/Input/` and are referenced from **Project Settings > Game > Delivery Game Input** (stored in `Config/DefaultGame.ini`). No hardcoded asset paths in C++, no Blueprint subclass needed for wiring.

| Asset | Type | Bindings |
|-------|------|----------|
| `IMC_Default` | Mapping context | W (Swizzle YXZ), S (Swizzle + Negate), D, A (Negate) → `IA_Move`; Mouse XY 2D → `IA_Look` |
| `IA_Move` | Axis2D | X = right, Y = forward |
| `IA_Look` | Axis2D | X = yaw, Y = pitch (inverted in code so mouse-up looks up) |

Sprint, Crouch, Interact, Flashlight and Pause actions are added in Milestone 2 together with the code that uses them.

## Rendering defaults (`Config/DefaultEngine.ini`)

- DX12, Lumen GI + Lumen reflections, **software** ray tracing (hardware RT off until profiled; RTX 4060-class is the reference GPU).
- Virtual Shadow Maps on, mesh distance fields on (required by software Lumen), static lighting disabled (fully dynamic — needed for flickering lights / paranormal lighting events).

## Maps

| Map | Purpose |
|-----|---------|
| `/Game/Maps/Dev/L_DevTest` | Graybox test map (floor, blocks, sun, sky, fog, PlayerStart). Editor startup + game default map until the farmhouse exists. |

## Planned architecture (not yet implemented)

- **Interaction** — `IDGInteractable` interface + `UDGInteractionComponent` on the character (line trace, focus, server RPC to interact). Milestone 2.
- **Houses** — `UDGHouseDefinition` primary data asset per house (id, name, level, entity, events, objectives, audio/lighting presets, difficulty); a world subsystem loads the active one. Milestone 3–5.
- **Paranormal events** — event objects driven by a server-side director with tension budget + cooldowns; results replicated. Milestone 4.
- **Entity AI** — AI controller + StateTree driven by an entity data asset. Milestone 4.
- **Online sessions** — choice of Steam vs EOS deferred to Milestone 6.

## Hardware note

Dev machine has 16 GB RAM. UBT throttles to ~10 parallel compile actions and system commit was ~97% during the first build. 32 GB is strongly recommended for editor + compile together.
