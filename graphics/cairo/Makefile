# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cairo
PORTVERSION=	1.14.6
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Vector graphics library with cross-device output support

LICENSE=	LGPL21 MPL
LICENSE_COMB=	dual

USES=		tar:xz

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpng.so:graphics/png \
		libfontconfig.so:x11-fonts/fontconfig

PORTSCOUT=	skipv:5c-1.1,5c-1.2,5c-1.5

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-html-dir=${DOCSDIR} \
		--disable-directfb \
		--enable-tee
USES+=		cpe libtool pathfix pkgconfig
CPE_VENDOR=	cairographics
USE_XORG=	pixman
USE_GNOME=	referencehack
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--with-html-dir=${DOCSDIR} \
		--disable-directfb \
		--disable-gallium \
		--disable-wgl \
		--enable-xlib-xcb \
		--enable-tee

OPTIONS_SUB=yes
OPTIONS_DEFINE=	EGL XCB GLIB X11
OPTIONS_DEFAULT=GL EGL XCB GLIB X11
OPTIONS_SLAVE=	${ARCH:tu}
OPTIONS_SINGLE=	OPENGL
OPTIONS_SINGLE_OPENGL= NOGL GL GLESV2
OPENGL_DESC=OpenGL backend
NOGL_DESC= 	None
X11_USE=	xorg=x11,xext,xrender
X11_CONFIGURE_ENABLE=xlib
GL_USE=	gl=gl xorg=glproto:both,dri2proto:both,dri3proto:both
GL_DESC=	2D/3D rendering support via OpenGL
GL_IMPLIES=	X11
GL_CONFIGURE_ENABLE=gl
GLESV2_USE=	gl=glesv2
GLESV2_DESC=2D/3D rendering support via OpenGL ES 2
GLESV2_CONFIGURE_ENABLE=glesv2
EGL_USE=	gl=egl
EGL_DESC=	Enable EGL functions
EGL_CONFIGURE_ENABLE=egl
GLIB_USE=	gnome=glib20
GLIB_DESC=	Enable GObject Functions Feature
GLIB_CONFIGURE_ENABLE=	gobject
XCB_USE=	xorg=xcb
XCB_DESC=	Enable XCB (X C-language Binding) Support
XCB_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xcb-renderutil.pc:x11/xcb-util-renderutil
XCB_RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xcb-renderutil.pc:x11/xcb-util-renderutil
XCB_CONFIGURE_ENABLE=	xcb
# this has another option --enable-xlib-xcb=auto but it is buggy.
MIPS_BUILD_DEPENDS=	${LOCALBASE}/include/atomic_ops.h:devel/libatomic_ops
MIPS_USES=	localbase
MIPS_CONFIGURE_ENV=	cairo_cv_atomic_primitives="libatomic-ops"

PLIST_SUB+=	LIBVER=2.11400.6

post-patch:
	@${REINPLACE_CMD} -e '/strings/s/ - / -a /' \
		-e '/test/s/==/=/g' \
		-e '/LIBS/s/-lrt//' -e '/LIBS/s|-ldld||' \
		-e '/LIBS/s|-ldl||' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-lcairo|-lcairo -lpthread|' \
		${WRKSRC}/src/*.pc.in
	@${REINPLACE_CMD} -e '/@CAIRO_HAS_PNG_FUNCTIONS_TRUE@.*=/d' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|-ldl||g' \
		${WRKSRC}/util/*/Makefile.in \
		${WRKSRC}/boilerplate/Makefile.in

.include <bsd.port.mk>

.endif
