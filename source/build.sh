gcc pwnme.c -fcf-protection=none -mshstk -z noexecstack -fno-stack-protector -o pwnme
strip --strip-all pwnme