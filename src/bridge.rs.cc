#include "lib/include/up-client-dummy-cpp/transport/dummyUTransport.h"
#include <cstddef>
#include <memory>
#include <new>
#include <type_traits>
#include <utility>

namespace rust {
inline namespace cxxbridge1 {
// #include "rust/cxx.h"

#ifndef CXXBRIDGE1_IS_COMPLETE
#define CXXBRIDGE1_IS_COMPLETE
namespace detail {
namespace {
template <typename T, typename = std::size_t>
struct is_complete : std::false_type {};
template <typename T>
struct is_complete<T, decltype(sizeof(T))> : std::true_type {};
} // namespace
} // namespace detail
#endif // CXXBRIDGE1_IS_COMPLETE

namespace {
template <bool> struct deleter_if {
  template <typename T> void operator()(T *) {}
};

template <> struct deleter_if<true> {
  template <typename T> void operator()(T *ptr) { ptr->~T(); }
};
} // namespace
} // namespace cxxbridge1
} // namespace rust

using DummyUTransport = ::DummyUTransport;

extern "C" {
::DummyUTransport *cxxbridge1$new_dummy_utransport() noexcept {
  ::std::unique_ptr<::DummyUTransport> (*new_dummy_utransport$)() = ::new_dummy_utransport;
  return new_dummy_utransport$().release();
}

static_assert(::rust::detail::is_complete<::DummyUTransport>::value, "definition of DummyUTransport is required");
static_assert(sizeof(::std::unique_ptr<::DummyUTransport>) == sizeof(void *), "");
static_assert(alignof(::std::unique_ptr<::DummyUTransport>) == alignof(void *), "");
void cxxbridge1$unique_ptr$DummyUTransport$null(::std::unique_ptr<::DummyUTransport> *ptr) noexcept {
  ::new (ptr) ::std::unique_ptr<::DummyUTransport>();
}
void cxxbridge1$unique_ptr$DummyUTransport$raw(::std::unique_ptr<::DummyUTransport> *ptr, ::DummyUTransport *raw) noexcept {
  ::new (ptr) ::std::unique_ptr<::DummyUTransport>(raw);
}
::DummyUTransport const *cxxbridge1$unique_ptr$DummyUTransport$get(::std::unique_ptr<::DummyUTransport> const &ptr) noexcept {
  return ptr.get();
}
::DummyUTransport *cxxbridge1$unique_ptr$DummyUTransport$release(::std::unique_ptr<::DummyUTransport> &ptr) noexcept {
  return ptr.release();
}
void cxxbridge1$unique_ptr$DummyUTransport$drop(::std::unique_ptr<::DummyUTransport> *ptr) noexcept {
  ::rust::deleter_if<::rust::detail::is_complete<::DummyUTransport>::value>{}(ptr);
}
} // extern "C"
