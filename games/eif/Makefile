# Created by: johans
# $FreeBSD$

PORTNAME=	eif
PORTVERSION=	1.3.4
PORTREVISION=	2
CATEGORIES=	games ipv6
MASTER_SITES=	http://www.stack.nl/~marcolz/empire/ \
		ftp://ftp.stack.nl/pub/users/johans/eif/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Empire text client

GNU_CONFIGURE=	yes
USES=		ncurses readline shebangfix
SHEBANG_FILES=	contrib/*.pl

NOPIE_PORTS=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e '/curout_isapipe/d' ${WRKSRC}/src/data.h
	@${REINPLACE_CMD} -e '/cd .(pkglibdir)/s/cd /&$$(DESTDIR)/' \
		${WRKSRC}/contrib/Makefile.in
	@${REINPLACE_CMD} -e 's@lcurses@lncurses@g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
