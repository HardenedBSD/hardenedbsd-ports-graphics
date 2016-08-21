# $FreeBSD$

PORTNAME=	libinput
PORTVERSION=	1.4.0
CATEGORIES=	wayland

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Generic input library

BUILD_DEPENDS=	v4l_compat>=0:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS=	libevdev.so:${PORTSDIR}/devel/libevdev \
				libepoll-shim.so:${PORTSDIR}/wayland/libepoll-shim \
				libwacom.so:${PORTSDIR}/wayland/libwacom \
				libudev.so:${PORTSDIR}/wayland/libudev-devd \
				libmtdev.so:${PORTSDIR}/devel/libmtdev

USE_GITHUB=	yes
GH_ACCOUNT=	jiixyj
GH_TAGNAME=	67c9796

USES=		autoreconf gmake libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
PATHFIX_MAKEFILEIN?=	Makefile.am

CPPFLAGS+=	-I${LOCALBASE}/include/libepoll-shim
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
