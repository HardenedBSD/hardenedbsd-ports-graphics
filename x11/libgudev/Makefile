# $FreeBSD$

MASTER_SITES= https://download.gnome.org/sources/libgudev/230/
PORTNAME=	libgudev
PORTVERSION=	230
PORTREVISION=	1
CATEGORIES=	x11
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	x11@FreeBSD.org
COMMENT= GObject bindings for libudev.

LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake libtool pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
