# HW3 for CPEG676

## gee-mail
A "simple" secure-email exchange program, using a sqlite3 database for user and mail storage, and utilizing crypto++ for encryption and hashing requirements.

### requires
  * libsqlite3-dev
  * libcrypto++-dev

### To use
```
make
run ./gee-mail.bin
```

### Caveats
  Usernames may be no longer than 40 characters, and may not include certain characters.
  sqlite3 database security not fully baked in (yet?)
