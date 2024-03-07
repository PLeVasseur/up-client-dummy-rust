use std::env;
use cxx_build::CFG;

fn main() {
    // Obtain the current directory of the build script
    let current_dir = env::current_dir().unwrap();

    // The `include_prefix` should remain a relative path
    CFG.include_prefix = "../up-client-dummy-cpp";

    // Define the relative path to the `up-cpp` directory
    let up_cpp_path = current_dir.join("../up-cpp");
    // Convert the relative path to an absolute path
    let up_cpp_path_abs = up_cpp_path.canonicalize().unwrap();
    // Push the absolute path to `CFG.exported_header_dirs`
    CFG.exported_header_dirs.push(&*up_cpp_path_abs);

    cxx_build::bridge("src/abc.rs")
        .file("lib/src/dummyUTransport.cpp")
        .std("c++17")
        .compile("up-client-dummy-rust");

    println!("cargo:rerun-if-changed=src/bridge.rs");
    println!("cargo:rerun-if-changed=lib/src/dummyUTransport.cpp");
    println!("cargo:rerun-if-changed=lib/include/up-client-dummy-cpp/transport/DummyUTransport.h");
}