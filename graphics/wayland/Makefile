# Created by: kwm@FreeBSD.org
# $FreeBSD$

PORTNAME=	wayland
PORTVERSION=	1.11.0
CATEGORIES=	graphics
MASTER_SITES= http://wayland.freedesktop.org/releases/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Wayland composite "server"

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2 \
				libffi.so:${PORTSDIR}/devel/libffi \
				libepoll-shim.so:${PORTSDIR}/devel/libepoll-shim
WITH_DEBUG=	1
USES=		autoreconf gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	libxslt:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-documentation
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
