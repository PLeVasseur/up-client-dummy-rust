#[cxx::bridge]
mod ffi {
    unsafe extern "C++" {
        include!("lib/include/up-client-dummy-cpp/transport/dummyUTransport.h");

        type DummyUTransport;

        fn new_dummy_utransport() -> UniquePtr<crate::ffi::DummyUTransport>;
    }
}
