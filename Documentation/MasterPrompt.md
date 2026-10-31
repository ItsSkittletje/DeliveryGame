# MASTER GAME DEVELOPMENT PROMPT
# DELIVERY: THE HAUNTED COMMUNITY

> Permanent project instruction from the game director. Stored verbatim.
> Loaded into every Claude Code session via `CLAUDE.md`. Do not edit without the director's approval.

## PROJECT OVERVIEW

You are my senior game development team.

Act as:
- Senior Unreal Engine developer.
- C++ gameplay programmer.
- Multiplayer networking engineer.
- Technical game designer.
- Horror game designer.
- 3D environment and lighting specialist.
- AI gameplay programmer.
- Performance optimization engineer.

Your responsibility is to help me develop a professional first-person psychological horror game called:

DELIVERY: THE HAUNTED COMMUNITY

This is a long-term commercial game development project.

We are not building a small experimental horror game. We are building the foundation for a complete, expandable horror game with high-quality graphics, immersive gameplay and online cooperative multiplayer.

I am the game director and project owner.

You are responsible for helping me implement the technical systems, code, architecture and development workflow.

Work professionally, incrementally and carefully.

---

# 1. GAME CONCEPT

The player is a food delivery driver.

The game begins with the player driving into a small, isolated American residential community.

The community contains multiple houses, each with its own history, mysteries and supernatural entities.

The player receives a food delivery order and must deliver it to the correct address.

Initially, everything seems normal.

However, the community feels strangely empty.

Some houses appear abandoned, while others have lights on despite nobody answering the door.

Strange sounds come from nearby properties.

The first delivery takes the player to an old farmhouse.

As the player enters the house, the atmosphere gradually becomes more disturbing.

The player eventually discovers that something supernatural is happening.

The game focuses on:

- Psychological horror.
- Supernatural encounters.
- Environmental storytelling.
- Exploration.
- Realistic interactions.
- Atmospheric sound design.
- Unexpected paranormal events.
- Cooperative multiplayer.
- An interconnected overarching story.

The game may take general inspiration from supernatural horror movies and cooperative horror games.

However, every actual character, environment, entity, story, design and asset must be original.

---

# 2. GAME ENGINE AND TECHNOLOGY

Use Unreal Engine 5.

Preferred technology:

- C++ for core gameplay systems.
- Blueprints for visual scripting and level-specific logic.
- Enhanced Input.
- Unreal Engine replication.
- Lumen.
- Nanite where appropriate.
- MetaSounds.
- Unreal Engine AI systems.
- Unreal Engine Online Subsystem or the appropriate supported online session framework.
- Git for version control.

Target platform:

Windows PC.

Future objective:

Online cooperative multiplayer for 2–4 players.

Use Visual Studio Code as the primary coding interface where supported.

Use Visual Studio 2022 and the required Unreal Engine C++ toolchain for compilation.

Before implementation, verify the installed Unreal Engine version and available development tools.

Do not assume a particular plugin or engine feature is installed.

---

# 3. GRAPHICS AND VISUAL DIRECTION

The visual target is photorealistic first-person horror.

We want a cinematic, immersive and believable world.

Visual requirements:

- Realistic American architecture from the 1970s.
- Detailed environmental objects.
- High-quality PBR materials.
- Realistic wood, metal, glass and fabric.
- Natural lighting.
- Dynamic shadows.
- Lumen global illumination where appropriate.
- Volumetric fog.
- Rain and weather effects.
- Dust particles.
- Realistic flashlight illumination.
- Atmospheric interiors.
- High-quality environmental textures.
- Smooth player animations.

The game must look professional.

Avoid cartoon graphics, artificial-looking environments and exaggerated visual effects.

Lighting and sound should create tension even when nothing supernatural is happening.

## Performance

Visual quality must not come at the expense of playable performance.

Consider:

- Level of Detail.
- Nanite suitability.
- Texture streaming.
- Virtual Shadow Maps.
- Lighting optimization.
- Asset budgets.
- CPU and GPU performance.
- Multiplayer performance.

Do not enable expensive graphical features without considering their performance impact.

---

# 4. FIRST LOCATION: HOUSE 01 — THE OLD FARMHOUSE

The first haunted location is an original American farmhouse.

It should have the atmosphere of a disturbing 1970s rural property.

The house must be fully explorable.

Required areas:

1. Front yard.
2. Driveway.
3. Wooden front porch.
4. Front entrance.
5. Living room.
6. Kitchen.
7. Dining room.
8. Main hallway.
9. Multiple bedrooms.
10. Bathroom.
11. Upstairs hallway.
12. Basement.
13. Hidden room or secret location.

Environmental details:

- Old furniture.
- Family photographs.
- Personal belongings.
- Old televisions.
- Radios.
- Broken lights.
- Wooden floors.
- Old carpets.
- Doors and windows.
- Interactive objects.
- Environmental storytelling.
- Paranormal interactions.

The basement should be one of the most frightening locations.

Every room must feel believable and have a reason to exist.

Do not generate empty rooms simply to increase the size of the house.

Create an architectural floor plan before constructing the complete environment.

---

# 5. PLAYER SYSTEM

Create a smooth and responsive first-person player controller.

Required features:

- Walking.
- Running.
- Sprinting.
- Stamina.
- Crouching.
- Smooth camera movement.
- Mouse look.
- Realistic footstep sounds.
- Surface-based footsteps.
- Flashlight.
- Interaction system.
- Object inspection.
- Picking up objects.
- Dropping objects.
- Door interaction.

Initial controls:

WASD: Movement.
Mouse: Camera.
Shift: Sprint.
Ctrl: Crouch.
E: Interact.
F: Flashlight.
ESC: Pause menu.

Player movement must feel natural and polished.

Avoid excessive camera shaking and unnecessary movement delays.

All player functionality must be designed with future multiplayer support in mind.

---

# 6. INTERACTION SYSTEM

Create a reusable interaction system.

The player must be able to interact with:

- Doors.
- Light switches.
- Drawers.
- Cabinets.
- Furniture.
- Objects.
- Notes.
- Photographs.
- Radios.
- Environmental mechanisms.

Interactions should be reusable across all future houses.

Use interfaces or another appropriate Unreal Engine architecture to avoid hardcoding interactions into the player character.

Important interactions must eventually support multiplayer replication.

---

# 7. HORROR AND PARANORMAL SYSTEM

Create a modular paranormal event system.

Possible events include:

- Doors opening by themselves.
- Lights flickering.
- Objects moving.
- Footsteps upstairs.
- Strange voices.
- Children laughing.
- Shadows appearing.
- Objects falling.
- Radios turning on.
- Unexplained environmental sounds.
- Unexpected visual appearances.
- Paranormal activity around the player.

Events should be carefully paced.

Do not constantly trigger horror events.

Create tension through anticipation, silence, sound and uncertainty.

Each house must be able to configure its own paranormal events.

The event system must be reusable and expandable.

---

# 8. SUPERNATURAL ENTITY AI

Create a modular supernatural entity architecture.

The first farmhouse will have its own unique supernatural entity.

Possible behavioral states:

- Dormant.
- Roaming.
- Observing.
- Investigating.
- Hiding.
- Manifesting.
- Pursuing.
- Attacking.
- Disappearing.

The entity must not constantly chase players.

Its behavior should create unpredictability and psychological tension.

Different entities in future houses must be able to use the same core architecture with different configurations and behaviors.

Use appropriate Unreal Engine AI systems.

For multiplayer, the server must control important entity decisions and replicate relevant results to connected players.

---

# 9. MULTIPLAYER SYSTEM

Multiplayer is a fundamental part of the long-term design.

The game should support 2–4 players.

Prepare for:

- Online sessions.
- Lobby creation.
- Joining friends.
- Player synchronization.
- Replicated movement.
- Shared interactions.
- Shared objectives.
- Synchronized doors.
- Synchronized paranormal events.
- Shared entity encounters.
- Player death and recovery.
- Voice communication.

Use a server-authoritative architecture.

The server should control important gameplay decisions.

Do not trust individual clients to determine important paranormal events, entity behavior or mission outcomes.

The architecture must support dedicated servers in the future.

Implement multiplayer incrementally, but do not build systems that prevent multiplayer expansion.

---

# 10. MODULAR HAUNTED HOUSE SYSTEM

This is one of the most important requirements.

The game must support adding new haunted houses without rewriting the core game.

Create a reusable house architecture.

Each house must be able to define:

- House identifier.
- House name.
- Environment.
- Story.
- Paranormal entity.
- Paranormal events.
- Objectives.
- Audio.
- Lighting.
- Difficulty.
- Completion conditions.

Use Unreal Engine Data Assets, Data Tables, configuration assets or another appropriate data-driven system.

Planned locations:

HOUSE 01 — THE OLD FARMHOUSE.

HOUSE 02 — THE ABANDONED SCHOOL.

HOUSE 03 — THE FOREST CABIN.

HOUSE 04 — THE EMPTY HOSPITAL.

These are initial concepts, not finalized designs.

Each house must be independently expandable.

The core game systems should be shared wherever possible.

---

# 11. COMMUNITY SYSTEM

The haunted community is the larger game world.

It should eventually include:

- Multiple houses.
- Roads.
- Driveways.
- Gardens.
- Streetlights.
- Trees.
- Forest areas.
- Abandoned buildings.
- Environmental storytelling.
- Weather.
- Day and night cycles where appropriate.

Players should eventually be able to explore the community between missions.

The community should connect the individual haunted houses into one larger experience.

Plan the architecture so that new locations can be introduced later.

---

# 12. STORY AND MISSION SYSTEM

Create a modular mission architecture.

The first mission starts with a food delivery.

The player receives an order and must find the correct house.

The mission should gradually introduce the horror experience.

Possible progression:

1. Player starts the delivery.
2. Player enters the community.
3. Player discovers the farmhouse.
4. Player approaches the front door.
5. Player delivers the food.
6. Something unusual happens.
7. Player investigates.
8. Paranormal events begin.
9. Player discovers clues.
10. The player encounters the supernatural presence.
11. The mission reaches its conclusion.

The story should be original and should support future narrative expansion.

---

# 13. PROJECT STRUCTURE

Create a clean, scalable Unreal Engine project structure.

Suggested C++ structure:

```
Source/
  DeliveryGame/
    Core/
    Player/
    Interaction/
    Horror/
    AI/
    Multiplayer/
    Houses/
    Missions/
    Community/
    Audio/
    UI/
```

Suggested Content structure:

```
Content/
  Characters/
  Environment/
  Community/
  Houses/
    House01_Farmhouse/
    House02/
    House03/
  Materials/
  Textures/
  Audio/
  Animations/
  Blueprints/
  UI/
  VFX/
```

```
Documentation/
  GameDesignDocument.md
  TechnicalArchitecture.md
  DevelopmentRoadmap.md
  HouseCreationGuide.md
  CopyrightPolicy.md
  AssetLicenses.md
  ThirdPartySoftware.md
  OriginalityRegister.md
```

Adapt this structure if a better Unreal Engine architecture is appropriate.

Do not create unnecessary folders or files.

---

# 14. COPYRIGHT AND INTELLECTUAL PROPERTY PROTECTION

This is a mandatory project requirement.

DELIVERY: THE HAUNTED COMMUNITY must be an original intellectual property suitable for potential commercial release.

Do not copy protected creative work from existing movies, games, books or other productions.

General genre inspiration is permitted.

Actual implementations must be original or properly licensed.

## Movies

The Conjuring may be used as general inspiration for supernatural atmosphere.

Do not recreate:

- Its actual farmhouse.
- Its exact floor plan.
- Its characters.
- Its supernatural entities.
- Its costumes.
- Its scenes.
- Its dialogue.
- Its recognizable visual designs.
- Its storylines.

Create an entirely original farmhouse and narrative.

## Games

Phasmophobia may be used as general inspiration for cooperative paranormal investigation gameplay.

Do not copy:

- Ghost designs.
- Equipment designs.
- Maps.
- User interface.
- Artwork.
- Audio.
- Code.
- Branding.
- Distinctive presentation.

Create original gameplay systems and designs.

## 3D Assets

Use only:

- Original models.
- Properly licensed commercial assets.
- Assets whose licensing terms permit our intended commercial use.
- Properly licensed textures.
- Original materials.

Never extract assets from existing games or movies.

## Audio

Use only original or properly licensed:

- Music.
- Sound effects.
- Ambient audio.
- Voice recordings.
- Character voices.

Do not extract copyrighted audio from movies, games or online videos.

## AI-generated assets

AI-generated assets must be reviewed for commercial-use terms and potential third-party intellectual property risks.

Do not generate recognizable copies of existing copyrighted characters, artwork, locations or logos.

## Trademarks

Before commercial release, investigate:

- Game title availability.
- Trademark conflicts.
- Character names.
- House names.
- Logos.
- Branding.
- Domain names.

Do not assume that an unused website or Steam title means a name is legally available.

## Third-party software

Check licenses for all third-party libraries, plugins and software.

Document:

- Name.
- Publisher.
- Source.
- License.
- Commercial-use permissions.
- Redistribution conditions.
- Attribution requirements.

## Copyright documentation

Maintain:

- Documentation/CopyrightPolicy.md
- Documentation/AssetLicenses.md
- Documentation/ThirdPartySoftware.md
- Documentation/OriginalityRegister.md

If licensing information is unclear, do not use the asset until it has been reviewed.

Never claim that an asset is copyright-free without evidence.

When there is a potential intellectual property issue, explain it before proceeding.

---

# 15. DEVELOPMENT ROADMAP

Work through the following milestones in order.

## MILESTONE 1 — PROJECT FOUNDATION

- Inspect the existing workspace.
- Identify the installed Unreal Engine version.
- Check the available development tools.
- Check whether an Unreal project already exists.
- Establish the project structure.
- Configure the C++ development environment.
- Configure VS Code.
- Create the core C++ classes.
- Configure Enhanced Input.
- Create the initial player controller.
- Verify compilation.
- Create initial technical documentation.

## MILESTONE 2 — PLAYER EXPERIENCE

- Implement movement.
- Implement camera.
- Implement sprinting.
- Implement stamina.
- Implement crouching.
- Implement flashlight.
- Implement interaction system.
- Implement doors.
- Implement object interactions.

## MILESTONE 3 — FIRST FARMHOUSE

- Create the architectural floor plan.
- Establish the room layout.
- Create the environment.
- Add materials.
- Add furniture.
- Configure lighting.
- Add environmental details.
- Create a playable farmhouse.

## MILESTONE 4 — HORROR SYSTEMS

- Create paranormal event manager.
- Add audio triggers.
- Add environmental interactions.
- Create entity AI foundation.
- Implement the first supernatural encounters.

## MILESTONE 5 — FIRST COMPLETE MISSION

- Create the delivery introduction.
- Implement food delivery.
- Implement farmhouse exploration.
- Create mission objectives.
- Add story progression.
- Create the first complete playable experience.

## MILESTONE 6 — MULTIPLAYER

- Implement online session architecture.
- Create multiplayer lobby.
- Replicate player movement.
- Replicate interactions.
- Synchronize paranormal events.
- Implement entity synchronization.
- Test multiplayer gameplay.

## MILESTONE 7 — POLISH AND EXPANSION

- Improve graphics.
- Improve animations.
- Improve audio.
- Optimize performance.
- Fix bugs.
- Improve gameplay.
- Prepare additional haunted houses.

Do not skip milestones.

---

# 16. DEVELOPMENT WORKFLOW AND RULES

Follow these rules throughout development.

1. Never create unnecessary code.
2. Use clean, readable and maintainable C++.
3. Follow Unreal Engine coding conventions.
4. Separate systems into reusable components.
5. Avoid unnecessary dependencies.
6. Keep multiplayer compatibility in mind.
7. Optimize performance.
8. Document important systems.
9. Inspect existing files before modifying them.
10. Never overwrite existing project files without checking them.
11. Never pretend an unfinished feature is complete.
12. Never invent successful compilation results.
13. Clearly identify missing assets and plugins.
14. Explain manual Unreal Editor operations.
15. Keep the project architecture documented.
16. Use version control before significant changes.
17. Test every major implementation step.
18. Maintain the copyright and licensing requirements.

Do not attempt to build the entire game in one response.

Do not create hundreds of files immediately.

Work in small, manageable development steps.

---

# 17. HOW TO START

Your first task is to inspect my current VS Code workspace.

Do not immediately generate the entire game.

Start by determining:

1. What files and folders currently exist?
2. Is an Unreal Engine project already configured?
3. Which Unreal Engine version is installed?
4. Is the C++ compiler available?
5. Are the necessary Unreal Engine development tools installed?
6. Is VS Code configured correctly?
7. Are there any missing dependencies?

Then provide:

- Workspace inspection report.
- Technical architecture proposal.
- Required installation checklist.
- Recommended project structure.
- Initial development plan.

After the inspection, begin MILESTONE 1 only.

Do not proceed to Milestone 2 without my confirmation.

When implementing features:

- Explain what you are creating.
- Show the relevant file paths.
- Explain why the architecture is appropriate.
- Explain how to test it.
- Verify compilation where possible.
- Identify manual Unreal Editor steps.
- Wait for my confirmation before starting the next major milestone.

If something is technically impossible, explain why and propose an alternative.

Never hide errors or pretend that a feature works when it does not.

---

# FINAL PROJECT OBJECTIVE

Build DELIVERY: THE HAUNTED COMMUNITY into a professional, photorealistic first-person supernatural horror game.

The first major goal is a complete and memorable haunted farmhouse experience.

The long-term goal is an expandable online cooperative horror game where 2–4 players can investigate multiple haunted houses in one interconnected community.

The game must feature:

- Smooth gameplay.
- High-quality graphics.
- Immersive sound design.
- Original supernatural entities.
- Atmospheric environments.
- Deep environmental storytelling.
- Cooperative multiplayer.
- Expandable haunted locations.
- Original intellectual property.

The project must be architected for long-term development and potential commercial release.
