# Created by yohanesu75@gmail.com
# $FreeBSD$

MASTER_SITES= https://download.gnome.org/sources/libgudev/230/
PORTNAME=	libgudev
PORTVERSION=	230
PORTREVISION=	1
CATEGORIES=	wayland
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	x11@FreeBSD.org
COMMENT= GObject bindings for libudev.

LICENSE= LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libudev.so:${PORTSDIR}/wayland/libudev-devd

USES=		gmake libtool pkgconfig pathfix
USE_GNOME=	glib20 introspection gnomedocutils
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
