# Taken from EDK2 commit message:
# https://github.com/tianocore/edk2/commit/be9470b3c91fc50436c15a76c85cdde940355b9f
#
# For more information see:
# https://bugzilla.tianocore.org/show_bug.cgi?id=1747

set -e

openssl req \
  -noenc \ # Prompts for password otherwise and fails if none provided
  -x509 \
  -newkey rsa:2048 \
  -outform PEM \
  -keyout PkKek1.private.key \
  -out PkKek1.pem

sed \
  -e 's/^-----BEGIN CERTIFICATE-----$/4e32566d-8e9e-4f52-81d3-5bb9715f9727:/' \
  -e '/^-----END CERTIFICATE-----$/d' \
  PkKek1.pem \
| tr -d '\n' \
> PkKek1.oemstr
