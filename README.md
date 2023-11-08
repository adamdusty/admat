# AdMat

Linear algebra lib specific to my use cases.

## Goals

- Don't explode compile time in my other projects.

## Plan

| Version | Features |
| ------- | -------- |
|0.1.0a| 2, 3, and 4 dimensional vector data structures|
|| Equality operators |
|| [+-] operators for vectors |
|| Dot and cross product for vectors |
|| Normalization, length |
| 0.2.0a | 4x4 matrix |
|| Equality operators |
|| Template identity constructor |
|| [+-] operators for general matrices|
|| Matrix multiplication |
|| Matrix * vector multiplication |
|| Determinant, inverse, transpose |
|0.3.0a| Implement all other WGSL spec vector functions |
|| Implement all other WGSL spec matrix functions |
|0.4.0a| Performance considerations |
|0.5.0a| Convenience functions |
|0.1.0b| Documentation |

### Notes

Not sure how I feel about matrix accessor indices. 1-indexed feels right mathematically, but inconsistent.
Should probably go with 0-indexed because that's what I did with vectors.

Add tests for matrix arithmetic properties (associtivity, etc.).
