Usage:

Overlay:

- Put this line in /etc/make.conf:

```
OVERLAYS+=/path/to/freebsd-ports-boost
```

For poudriere:

```
sudo poudriere ports -c -F -p boostwip
cd ${LOCALBASE}/poudriere/ports/boostwip
git clone https://github.com/fluffykhv/freebsd-ports-boost .
poudriere bulk -j 121amd64 -p portstree -O boostwip category/port 
```
