# Created by: ijliao
# $FreeBSD$

PORTNAME=	fwlogwatch
PORTVERSION=	1.5
CATEGORIES=	security
MASTER_SITES=	http://fwlogwatch.inside-security.de/sw/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Packet filter and firewall log analyzer

BROKEN_FreeBSD_9=	Fails to build due to outdated flex

USES=		gettext tar:bzip2
MAKE_ENV=	MKDIR="${MKDIR}"
INSTALL_TARGET=	install install-config install-i18n

NOPIE_PORTS=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,/etc,${PREFIX}/etc,g" ${WRKSRC}/fwlogwatch.8

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/fwlogwatch.sh.sample \
		${STAGEDIR}${PREFIX}/etc/rc.d

.include <bsd.port.mk>
