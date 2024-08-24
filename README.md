# lxc benchmark
Test the benchmark performance of lxcfs.

LXC Benchmark is a tool designed to test and evaluate the benchmark performance of LXCFS (LXC Filesystem).

## Build

1. Clone the repository:

   ```bash
   git clone https://github.com/oplxc/lxcbenchmark.git
   cd lxcbenchmark
   #or wget https://github.com/oplxc/lxcbenchmark/archive/refs/heads/main.zip
   ```

2. Build the project:

   ```bash
   make
   #make static
   ```
3. setting thread:
```bash
export thd=1
```
4. running test:

   ```bash
   ./lxcbk
   ```

## Usage

To run the benchmark tests, use the following command:
```bash
./lxcbk [anything]
```

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments

- [LXCFS](https://github.com/lxc/lxcfs) for providing the userspace filesystem for containers.
- [LXC](https://linuxcontainers.org/lxc/) for the container management framework.

## Features

- rename ANYTHING, you can rename it like "nginx"
- options ANYTHING, you can using any Options to start like "-s reload"
- So, you can start lxc benchmark as "nginx -s reload"

## Help
Use -h to get helpinfo
