# $FreeBSD$

PORTNAME=	libinput
PORTVERSION=	1.4.0
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Generic input library

BUILD_DEPENDS=	v4l_compat>=0:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS=	libevdev.so:${PORTSDIR}/devel/libevdev \
				libepoll-shim.so:${PORTSDIR}/devel/libepoll-shim

USE_GITHUB=	yes
GH_ACCOUNT=	jiixyj
GH_TAGNAME=	67c9796

USES=		autoreconf gmake libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
PATHFIX_MAKEFILEIN?=	Makefile.am

CONFIGURE_ARGS+= --disable-wacom

CPPFLAGS+=	-I${LOCALBASE}/include
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
