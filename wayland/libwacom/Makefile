# Created by yohanesu75@gmail.com
# $FreeBSD$

MASTER_SITES= https://sourceforge.net/projects/linuxwacom/files/libwacom/
PORTNAME=	libwacom
PORTVERSION=	0.22
PORTREVISION=	1
CATEGORIES=	wayland
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Adds tablet support to libinput

LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgudev-1.0.so:${PORTSDIR}/wayland/libgudev

CONFIGURE_ENV+=	PKG_CONFIG_PATH=${STAGEDIR}${PREFIX}/libdata/pkgconfig

USES=		gmake libtool pkgconfig pathfix
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
