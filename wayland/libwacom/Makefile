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

BUILD_DEPENDS=	v4l_compat>=0:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS=	libgudev-1.0.so:${PORTSDIR}/wayland/libgudev

USES=		gmake libtool pkgconfig gnome
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
