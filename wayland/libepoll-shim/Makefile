# Created by yohanesu75@gmail.com
# $FreeBSD$

PORTNAME= libepoll-shim
PORTVERSION= 0.1
CATEGORIES=	wayland

MAINTAINER=	x11@FreeBSD.org
COMMENT=	epoll shim implemented using kevent

USE_GITHUB=	yes
GH_ACCOUNT=	jiixyj
GH_PROJECT=	epoll-shim
GH_TAGNAME=	b2de08a

USE_LDCONFIG= yes

# TODO: Use automatic installer (make).
# Problem: Installs to /usr/lib. How to set correct install folder?
do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/sys
	${INSTALL_DATA} ${WRKSRC}/include/sys/epoll.h ${STAGEDIR}${PREFIX}/include/sys/epoll.h
	${INSTALL_DATA} ${WRKSRC}/include/sys/signalfd.h ${STAGEDIR}${PREFIX}/include/sys/signalfd.h
	${INSTALL_DATA} ${WRKSRC}/include/sys/timerfd.h ${STAGEDIR}${PREFIX}/include/sys/timerfd.h
	${INSTALL_LIB} ${WRKSRC}/libepoll-shim.a ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_LIB} ${WRKSRC}/libepoll-shim.so.0 ${STAGEDIR}${PREFIX}/lib/
	${LN} -sf libepoll-shim.so.0 ${STAGEDIR}${PREFIX}/lib/libepoll-shim.so

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libepoll-shim.so.0

.include <bsd.port.mk>
