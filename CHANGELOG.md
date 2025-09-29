# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Added

## [0.1.0] - 2025-09-28

### Added

- Prototypes to advin.h
- Makefile
- `get_string()`'s first implementation with dynamic memory allocation with guardrails ensuring safe string input is provided to the user.

## [0.2.0] - 2025-09-28

### Added
- `get_int()` to provide validated integer input to the user.

## [0.2.1] - 2025-09-28

### Fixed
- `get_int()`'s wrong validation leading to not providing input even if it is right.

## [0.2.2] - 2025-09-29

### Fixed
- `get_int()`'s memory issue where it didn't free the input variable containing the input in string format.
