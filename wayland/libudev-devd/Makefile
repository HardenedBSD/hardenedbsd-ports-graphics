# $FreeBSD$

PORTNAME=	libudev-devd
PORTVERSION=	0.1
CATEGORIES=	wayland

MAINTAINER=	x11@FreeBSD.org
COMMENT=	libudev-compatible interface for devd

BUILD_DEPENDS=	v4l_compat>=0:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS=	libevdev.so:${PORTSDIR}/devel/libevdev

USE_GITHUB=	yes
GH_ACCOUNT=	wulf7
GH_TAGNAME=	3fd2d11

USES=		autoreconf gmake libtool pkgconfig pathfix
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|$$(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.am

.include <bsd.port.mk>
