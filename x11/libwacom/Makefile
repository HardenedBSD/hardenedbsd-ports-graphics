#
# http://downloads.sourceforge.net/project/linuxwacom/libwacom/libwacom-0.22.tar.bz2
#


MASTER_SITES= https://sourceforge.net/projects/linuxwacom/files/libwacom/
PORTNAME=	libwacom
PORTVERSION=	0.22
PORTREVISION=	1
CATEGORIES=	x11
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Add tablet support to libinput, required.

LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgudev-1.0.so:${PORTSDIR}/x11/libgudev

USES=		gmake libtool pkgconfig gnome
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
# CPPFLAGS+=	-I${LOCALBASE}/include
# LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
