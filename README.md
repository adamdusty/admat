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
- [ ] Vector clamp and smoothstep
- [ ] Performance considerations (Initial implementations naive)

0.5.0a

- [ ] mat perspective
- [ ] mat orthoganol
- [ ] mat look at
- [ ] mat rotate
- [ ] mat scale
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
