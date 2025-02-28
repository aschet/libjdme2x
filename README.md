# libjdme2x

This library is a work-in-progress implementation of the I++ DME 2.5 protocol, as defined in the
[VDMA 8722](https://www.dinmedia.de/en/technical-rule/vdma-8722/378593245) standard, based on C++17
and the Boost library. I++ DME was developed in early 2000 by the automotive
industry and several measuring machine manufacturers to ensure interoperability between measuring
software and coordinate measuring machines (CMMs) from different manufacturers. Compliant products
are offered, for example, by Carl Zeiss, Hexagon, Renishaw and Wenzel.

## Contribution

The [LLVM coding standard](https://llvm.org/docs/CodingStandards.html) is used by this project.
All code will be licensed under the Boost Software License 1.0. Format code contributions with
clang-format and the provided configuration file and also provide unit/functional tests. Try to
avoid adding dependencies beyond the Boost library.

The following exceptions were applied to the LLVM coding stantard:
- The usage of iostream, RTTI and exceptions is permitted.
- Variable names start with lower case.

## Resources

- [ANTLR v4 grammar for the formal syntax of I++ DME](schemas/IPPDME.g4)

## References

- [I++ DME OpenSource Project](https://sourceforge.net/projects/iplusplusdme)
- [NIST I++ DME Suites (via Internet Archive)](https://web.archive.org/web/20150906063106/http://www.isd.mel.nist.gov/projects/metrology_interoperability/NISTactivities.htm)
- [Last publicly available version of the I++ DME specification](https://sourceforge.net/projects/iplusplusdme/files/Specification%20documents/I%2B%2B%20V1.7%20specifications/I%2B%2BDME%20specification%20document%201.7.pdf)