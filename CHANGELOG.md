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

## [0.3.0] - 2025-09-30

### Added
- `get_uint()`'s first implementation to provide users validated unsigned integer input.

### Removed
- `get_byte()`'s prototype was removed from advin.h because it is an redundan type.

## [1.0.0] - 2025-09-30

### Added
- `get_char()`'s first implementation
- `get_long_long()`'s first implementation
- `get_long()`'s first implementation
- `get_long_long_uint()`'s first implementation
- `get_long_uint()`'s first implementation
- `get_short_uint()` prototype to advin.h
- `get_short()`'s first implementation
- `get_float()`'s first implementation
- `get_double()`'s first implementation
- `get_long_double()`'s first implementation

### Changed
- `get_long` to use `get_long_long()` (to remove redundancy and develop efficiently)
- `get_int()` to use `get_long_long()` (to remove redundancy and develop efficiently)
- `get_long_uint` to use `get_long_long_uint()` (to remove redundancy and develop efficiently)
- `get_uint` to use `get_long_long_uint()` (to remove redundancy and develop efficiently)
