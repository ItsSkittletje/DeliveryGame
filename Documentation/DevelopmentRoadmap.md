# Development Roadmap

Milestones are defined in `MasterPrompt.md` §15. Each requires director sign-off before the next begins.

| # | Milestone | Status |
|---|-----------|--------|
| 1 | Project Foundation | **Complete** (2026-11-01) |
| 2 | Player Experience | Not started — awaiting M1 sign-off |
| 3 | First Farmhouse | Not started |
| 4 | Horror Systems | Not started |
| 5 | First Complete Mission | Not started |
| 6 | Multiplayer | Not started |
| 7 | Polish and Expansion | Not started |

## Milestone 1 checklist

- [x] Inspect workspace (empty; no prior project) — 2026-10-31
- [x] Git for Windows 2.56 installed (includes Git LFS)
- [x] Visual Studio 2022 Community + Unreal C++ workloads — MSVC 14.44.35207 (v143), Windows SDK 10.0.22621 / 10.0.26100
- [x] Unreal Engine 5.8.4 installed via Epic Games Launcher
- [x] Unreal C++ project `DeliveryGame` created
- [x] Git repository initialised, LFS enabled, first commit
- [x] VS Code configured (C/C++ extension pack, UBT-generated workspace + compile commands)
- [x] Core C++ classes: GameMode, GameState, PlayerController, PlayerState, Character
- [x] Enhanced Input: `IMC_Default`, `IA_Move`, `IA_Look` (remaining actions arrive with their M2 features)
- [x] Compilation verified — `DeliveryGameEditor Win64 Development`, Result: Succeeded, 0 warnings (2026-10-31)
- [x] Headless boot verified — loads `L_DevTest`, game class `DGGameMode`, no input warnings
- [x] Technical documentation: TechnicalArchitecture.md
- [x] Copyright documentation skeletons
- [x] Director play-test in editor (walk + mouse look) — approved 2026-11-01
