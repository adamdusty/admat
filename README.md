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
- [ ] Determinant, inverse, transpose

0.3.0a

- [ ] Implement all other WGSL spec vector functions
- [ ] Implement all other WGSL spec matrix functions

0.4.0a

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

- [ ] docs

0.2.0b

- [ ] quaternion data structure
- [ ] quaternion from euler
- [ ] quaternion inverse

### Notes

Not sure how I feel about matrix accessor indices. 1-indexed feels right mathematically, but inconsistent.
Should probably go with 0-indexed because that's what I did with vectors.

Add tests for matrix arithmetic properties (associtivity, etc.).
