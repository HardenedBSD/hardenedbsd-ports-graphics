# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libdevq
PORTVERSION=	0.0.3
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Generic Device Query and Monitor interface

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd

GNU_CONFIGURE=	yes
USES=		autoreconf libtool pathfix #tar:xz
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

PATHFIX_MAKEFILEIN=	Makefile.am

OPTIONS_DEFINE=	PROGRAMS
OPTIONS_SUB=	yes
PROGRAMS_DESC=	Build diagnostic programs
PROGRAMS_CONFIGURE_ENABLE=programs

.include <bsd.port.mk>
