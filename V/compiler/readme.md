# ⚡ V-Engine: The Next-Gen Compiler Architecture

Welcome to **V-Engine**, a brutally fast, native, and modular compiler designed to bypass the heavy overhead of traditional VMs (like Node.js or Python). V-Engine compiles directly to ARM64/x86 native machine code, providing zero-latency execution.

## 🚀 Core Philosophy
1. **Zero-Overhead:** No garbage collection pauses. No event loop blocking.
2. **Modular Architecture:** The core engine is extremely lightweight. Everything else (UI, Network, AI, Discord) is handled via dynamic `.so` plugins loaded autonomously via `dlopen`.
3. **English-First Syntax:** Clean, globally standardized syntax designed for maximum readability.

---

## 🎮 Plugin 1: VDiscord
VDiscord is a revolution in Discord bot development. It completely replaces `discord.js` by running at native C++ speeds directly on the hardware. 

### Why VDiscord?
* **Zero-Cache Mode:** Capable of running in 0 MB RAM mode. It doesn't cache millions of users; it routes events directly to your logic.
* **Hot-Reloading:** Update commands on the fly without disconnecting the websocket.
* **Native Anti-Spam:** C++ level rate-limiting built into the core.

### 📚 VDiscord API Reference

#### `setup(token: string, zeroCache: bool, intents: int)`
Initializes the VDiscord engine.
* *Example:* `djs.setup("TOKEN", ZeroCache: true, Intents: 32767)`

#### `sendMessage(channelId: string, content: string)`
Sends a plain text message to a specified channel with sub-millisecond network dispatching.

#### `sendEmbed(channelId: string, title: string, description: string, hexColor: int)`
Memory-safe embed builder. Replaces the clunky 10-line `EmbedBuilder` in discord.js with a single, high-performance function.
* *Example:* `djs.sendEmbed("123", "Stats", "Running V-Engine", 0xFF0000)`

#### `banUser(guildId: string, userId: string, reason: string, pruneDays: int)`
Bans a user from a guild instantly.

#### `kickUser(guildId: string, userId: string, reason: string)`
Kicks a user from the specified guild.

#### `timeoutUser(guildId: string, userId: string, durationSec: int, reason: string)`
Applies a timeout (mute) to a user for a specified duration in seconds.

#### `setStatus(statusText: string, activityType: string)`
Updates the bot's rich presence dynamically.

---

## 🖥️ Plugin 2: VTML (V-Terminal Markup Language)
VTML is a hyper-optimized UI engine for rendering graphical interfaces directly inside the terminal (TermUI) or via overlay rendering. It is designed specifically for building hack menus, admin dashboards, and system monitoring tools without needing a heavy DOM (like HTML).

### 📚 VTML API Reference

#### `render(layout: string)`
Parses and mounts a VTML layout to the active display buffer.

#### `createButton(id: string, label: string, onClick: function)`
Generates an interactive button component with a direct memory-mapped callback.

#### `drawESP(x: float, y: float, label: string)`
*(Gaming/Modding Specific)* Draws a high-performance bounding box (ESP) overlay at specific screen coordinates bypassing the OS window manager.

#### `readMemory(address: hex)`
*(Sandbox Specific)* Safely reads values from specified memory addresses for educational modding and debugging.

---
*Built with absolute precision by the Chief Engineer.*
