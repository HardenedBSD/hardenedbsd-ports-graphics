# Created by: gahr
# $FreeBSD$

PORTNAME=	libosmesa
PORTVERSION=	${MESAVERSION}
CATEGORIES=	graphics

COMMENT=	Off-Screen Mesa implementation of the OpenGL API

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2 \
		libglapi.so:${PORTSDIR}/graphics/libglapi
# depend on libGL? osmesa.h uses GL/gl.h

.include <bsd.port.options.mk>

.include "${.CURDIR}/../../graphics/libGL/Makefile.common"

#MESA_BUILD_WRKSRC=	src/util src/glsl src/mesa #/drivers/osmesa
MESA_INSTALL_WRKSRC=	src/mesa/drivers/osmesa

# before pulling this port into the mesa framework it was at verion 10.2.7
# due to this we can't unset WITH_NEW_MESA because then the version would
# go backwards.
WITH_NEW_MESA=1

.include "${.CURDIR}/../../graphics/libGL/Makefile.targets"

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/GL
	${INSTALL_DATA} ${WRKSRC}/include/GL/osmesa.h \
		${STAGEDIR}${PREFIX}/include/GL/

.include <bsd.port.mk>
