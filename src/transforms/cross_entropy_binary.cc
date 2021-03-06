#include "transforms/cross_entropy_binary.h"

#include "blitz.h"

namespace blitz {

template<template <typename> class TensorType, typename DType>
DType CrossEntropyBinary<TensorType, DType>::Apply(
  const shared_ptr<TensorType<DType> > output,
  const shared_ptr<TensorType<DType> > target) {
  return Backend<TensorType, DType>::CrossEntropyBinaryApplyFunc(
    output.get(), target.get());
}

template<template <typename> class TensorType, typename DType>
void CrossEntropyBinary<TensorType, DType>::Derivative(
  const shared_ptr<TensorType<DType> > output,
  const shared_ptr<TensorType<DType> > target,
  shared_ptr<TensorType<DType> > result) {
  Backend<TensorType, DType>::CrossEntropyBinaryDerivativeFunc(
    output.get(), target.get(), result.get());
}

INSTANTIATE_CLASS_CPU(CrossEntropyBinary);
#ifdef BLITZ_USE_GPU
  INSTANTIATE_CLASS_GPU(CrossEntropyBinary);
#endif

}  // namespace blitz
