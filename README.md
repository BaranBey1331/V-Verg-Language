<div align="center">
<h1>🚀 V-Verg-Language</h1>
<p><b>Advanced Tooling, Engine Optimization, and Mobile IDE Integration for the V Programming Language</b></p>
​<p>
<a href="#english-documentation">🇬🇧 English</a> •
<a href="#türkçe-dokümantasyon">🇹🇷 Türkçe</a>
</p>
</div>
​<h2 id="english-documentation">🇬🇧 English Documentation</h2>
​Table of Contents
​Introduction
​Vision and Philosophy
​Core Features
​Project Architecture
​Deep Dive: V-Engine Optimizer
​Mobile Development: Acode Editor Plugin
​VSupport & Inline Capabilities
​Installation & Setup
​Usage & Examples
​Troubleshooting & FAQ
​Roadmap
​Contributing
​License
​Introduction
​V-Verg-Language is an ambitious extension and tooling ecosystem designed for the V Programming Language. While V is known for its incredible compilation speed, safety, and C translation capabilities, writing and optimizing V code on mobile devices (specifically Android) has historically been challenging.
​This project bridges the gap by providing deeply integrated mobile editor support (via the Acode app), introducing specialized inline compiler plugins (VSupport), and implementing a custom V-Engine optimizer (v_optimizer.v) to maximize runtime efficiency.
​Vision and Philosophy
​Our goal is simple: Empower developers to write, compile, and optimize V code anywhere, even on their smartphones.
We believe that the future of programming is not strictly tied to desktop environments. By integrating directly into Android's filesystem (/storage/emulated/0/...) and popular mobile IDEs like Acode, we are decentralizing the development experience.
​Core Features
​⚡ V-Engine Optimizer: A dedicated optimization module (v_optimizer.v) designed to streamline abstract syntax tree (AST) evaluation and memory allocation specific to our custom workflows.
​📱 Acode IDE Integration: A fully functional, custom-built plugin (acode_v_plugin) that brings syntax highlighting, auto-completion, and compiler hooks directly to the Acode editor on Android.
​🧩 VSupport Inline Enhancements: Custom compiler plugins designed to extend V's native inline capabilities, allowing for better interoperability and lower-level system access.
​🌍 Cross-Platform Ready: While optimized for mobile (Android/Termux), the core optimization logic remains highly compatible with standard Linux and Windows V installations.
​Project Architecture
​The repository is structured to separate the mobile editor plugin from the core compiler extensions and optimization logic. Here is the detailed layout:
