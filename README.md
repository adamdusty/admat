# AdMat

Linear algebra lib specific to my use cases.

## Goals

- Don't explode compile time in my other projects.

## Plan

0.1.0a

- [x] 2, 3, and 4 dimensional vector data structures
- [x] Equality operators
- [x] [+-] operators for vectors
- [x] Dot and cross product for vectors
- [x] Normalization, length

0.2.0a

- [x] 4x4 matrix
- [x] Equality operators
- [x] Template identity constructor
- [x] [+-] operators for general matrices
- [x] Matrix multiplication
- [x] Matrix * vector multiplication
- [x] Determinant
- [ ] Inverse
  - 2x2, 3x3, and 4x4
  - Possible optimization is special case where matrix has no scaling factor
  - Not sure if I want to implement general inverse algorithm, since I won't ever need it
- [x] Transpose

0.3.0a

- [x] Vector clamp and smoothstep
- [x] Performance considerations (Initial implementations naive)
  - Implement basic benchmarks

0.4.0a

- [ ] mat perspective
- [ ] mat orthoganol
- [ ] mat look at
- [x] mat translate
- [x] mat rotate
  - I think quaternions will be a better solution for rotations. Building rotation matrices from a vector of angles feels like the wrong solution, but once I have quaternions implemented, I'll benchmark both.
- [x] mat scale
- [ ] vec distance
- [ ] vec reflect
- [ ] vec refract
- [ ] lerp

0.1.0b

- [ ] Test that matrix and vector functions hold to expected properties (Associativity, etc.)
- [ ] docs

0.2.0b

- [ ] quaternion data structure
- [ ] quaternion from euler
- [ ] quaternion inverse

### Notes

Matrix inversion is unpleasant
