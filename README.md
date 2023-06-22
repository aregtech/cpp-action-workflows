# AREG SDK Demo Project

---

## Repository Status

[![CMake](https://github.com/aregtech/cpp-action-workflows/actions/workflows/cmake.yml/badge.svg?branch=master)](https://github.com/aregtech/cpp-action-workflows/actions/workflows/cmake.yml)
[![MSBuild](https://github.com/aregtech/cpp-action-workflows/actions/workflows/msbuild.yml/badge.svg?branch=master)](https://github.com/aregtech/cpp-action-workflows/actions/workflows/msbuild.yml)

---

## Introduction

While was developing the [AREG SDK](https://github.com/aregtech/areg-sdk/), I spent lot of time to look for various workflow actions to automate build and test run. I've seen many examples and experiments and finally decided to share my with others. These workflows for sure are not the optimal, it is out of the agenda, but I hope it is a good practice. Let's say, this is kind of playground.

I've used [areg-sdk-demo](https://github.com/aregtech/areg-sdk-demo) template repository, it compiles with CMake, Make, Microsoft Visual Studio and compiles with  Windows Subsystem for Linux (WSL). I addition, it has  [areg-sdk](https://github.com/aregtech/areg-sdk/) as a submodule and has google tests. So, it has enough complication.

---

## Clone Sources

To clone the  repository, follow these steps in your desired directory (such as the `projects` directory):

* Run the following command **to clone the repository and its submodules**:
   ```bash
   git clone --recurse-submodules https://github.com/aregtech/cpp-action-workflows.git
   ```
   It is important to clone the AREG SDK *submodule* as well. This command ensures that both the main repository and its submodule are cloned.

* If you have already cloned the main repository but missed cloning the submodule, you can **update the submodules** separately by running the following command:
   ```bash
   git submodule update --init --recursive
   ```
   This command initializes and updates the submodules within the repository.

* The AREG SDK also has dependencies on [Google Unit Test](https://github.com/google/googletest), which is automatically cloned with the AREG SDK sources. **To update to the latest submodule sources**, use the following git command:
   ```bash
   git submodule update --remote --recursive
   ```
   This command updates the submodules, including the Google Unit Test submodule, to the latest version.

---

## Workflows

The workflows are located in the [.github/workflows](https://github.com/aregtech/cpp-action-workflows/tree/master/.github/workflows) directory. I'll periodically add and/or update them.

---

## License

The files and sources in this repository are provided under the [MIT License](https://github.com/aregtech/areg-sdk-demo/blob/main/LICENSE). They are offered without any warranty or restriction, allowing you the freedom to use them in any kind of project.

---
