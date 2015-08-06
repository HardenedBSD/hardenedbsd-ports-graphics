# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clinfo
PORTVERSION=	0.0.0.${DATESTAMP}
CATEGORIES=	devel

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	OpenCL info program like glxinfo is for libGL

# We need OpenCL header, we don't care if it is either Clover or Beignet.
BUILD_DEPENDS=	${LOCALBASE}/include/CL/opencl.h:${PORTSDIR}/lang/beignet
LIB_DEPENDS=	libOpenCL.so:${PORTSDIR}/devel/ocl-icd

DATESTAMP=	20150127

USE_GITHUB=	yes
GH_ACCOUNT=	Oblomov
GH_TAGNAME=	0d36ed9

USES=		gmake
NO_CONFIGURE=	yes
ALL_TARGET=	#
PLIST_FILES=	bin/clinfo \
		man/man1/clinfo.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|-Wall|-Wall -I${LOCALBASE}/include|g; \
		s|-lOpenCL|-lOpenCL -L${LOCALBASE}/lib|g' \
		${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/clinfo ${STAGEDIR}${PREFIX}/bin/
	@${INSTALL_MAN}	${WRKSRC}/man/clinfo.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
