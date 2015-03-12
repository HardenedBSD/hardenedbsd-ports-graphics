# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ocl-icd
PORTVERSION=	2.2.3
CATEGORIES=	lang
MASTER_SITES=	https://forge.imag.fr/frs/download.php/598/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	TBD

USES=		gmake libtool
GNU_CONFIGURE=	yes
USE_CSTD=	gnu89
USE_RUBY=	yes
RUBY_NO_RUN_DEPENDS=yes

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes

MANPAGES_BUILD_DEPENDS=	xmlto:${PORTSDIR}/textproc/xmlto \
			asciidoc:${PORTSDIR}/textproc/asciidoc

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/|${LOCALBASE}/etc/|g' \
		${WRKSRC}/doc/libOpenCL.7.txt \
		${WRKSRC}/ocl_icd_loader.c

.include <bsd.port.mk>
