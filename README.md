# AdMat

Linear algebra lib specific to my use cases.

## Goals

- Don't explode compile time in my other projects.

## Plan

0.1.0a

- [x] 2, 3, and 4 dimensional vector data structures
- [x] [+-] operators for vectors
- [x] Dot and cross product for vectors
- [x] Normalization, length

0.2.0a

- [x] 4x4 matrix
- [x] [+-] operators for general matrices
- [x] Matrix multiplication
- [x] Matrix * vector multiplication
- [x] Determinant
- [x] Inverse
- [x] Transpose

0.3.0a

- [x] Vector clamp and smoothstep
- [x] Performance considerations (Initial implementations naive)
  - Implement basic benchmarks

0.4.0a

- [x] mat perspective
- [x] mat orthogonal
- [x] mat look at
- [x] mat translate
- [x] mat rotate
  - I think quaternions will be a better solution for rotations. Building rotation matrices from a vector of angles feels like the wrong solution, but once I have quaternions implemented, I'll benchmark both.
- [x] mat scale
- [x] vec distance
- [x] vec reflect
- [x] vec refract
- [x] lerp

0.5.0a

- [ ] quaternion