# $FreeBSD$

PORTNAME=	sway
PORTVERSION=0.9
CATEGORIES=	wayland

MAINTAINER=	x11@FreeBSD.org
COMMENT=	i3-compatible Wayland compositor

USE_GITHUB=	yes
GH_ACCOUNT=	SirCmpwn
GH_TAGNAME=	0.9

USES=		cmake pkgconfig pathfix
USE_GCC=	any

LIB_DEPENDS= \
		libwlc.so:${PORTSDIR}/wayland/wlc					\
		libwayland-server.so:${PORTSDIR}/wayland/wayland	\
		libwayland-client.so:${PORTSDIR}/wayland/wayland	\
		libwayland-cursor.so:${PORTSDIR}/wayland/wayland	\
		libepoll-shim.so:${PORTSDIR}/wayland/libepoll-shim	\
		libcairo.so:${PORTSDIR}/graphics/cairo				\
		libpango-1.0.so:${PORTSDIR}/x11-toolkits/pango		\
		libpcre.so:${PORTSDIR}/devel/pcre					\
		libjson-c.so:${PORTSDIR}/devel/json-c				\
		libgdk_pixbuf-2.0.so:${PORTSDIR}/graphics/gdk-pixbuf2

# For image capture
#		libMagickCore-6.so:${PORTSDIR}/graphics/ImageMagick
# For video capture
#		libavutil.so:${PORTSDIR}/multimedia/ffmpeg


#BUILD_DEPENDS+=	${NONEXISTENT}:${PORTSDIR}/wayland/wayland-protocols
#BUILD_DEPENDS+=	wayland-scanner:${PORTSDIR}/wayland/wayland
BUILD_DEPENDS+=	a2x:${PORTSDIR}/textproc/asciidoc

#RUN_DEPENDS=	${LOCALBASE}/lib/libglapi.so.0:${PORTSDIR}/graphics/libglapi

CPPFLAGS+=	-I${LOCALBASE}/include

LDFLAGS+=	-lepoll-shim -lrt

post-install:
	@chmod a+s ${STAGEDIR}${PREFIX}/bin/sway

.include <bsd.port.mk>
