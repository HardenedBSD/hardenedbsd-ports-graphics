# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xorg-vfbserver

COMMENT=	X virtual framebuffer server from X.Org

MASTERDIR=	${.CURDIR}/../xorg-server
DESCR=		${.CURDIR}/pkg-descr

CONFIGURE_ARGS=	--disable-dmx \
		--disable-xephyr \
		--disable-xnest \
		--disable-kdrive \
		--disable-xfbdev \
		--disable-xfake \
		--disable-screensaver \
		--disable-xwin \
		--disable-xwayland \
		--disable-xorg \
		--without-xmlto \
		--disable-docs \
		--disable-devel-docs \
		--localstatedir=/var \
		--without-dtrace \
		--without-doxygen \
		--disable-glx \
		--disable-dri  \
		--disable-config-hal \
		--disable-libdrm \
		--disable-glx-tls \
		--disable-vbe \
		--disable-vgahw \
		--enable-xvfb \
		--with-fontrootdir=${PREFIX}/share/fonts

USE_XORG=	pixman x11 fixesproto damageproto xcmiscproto xtrans \
		bigreqsproto randrproto renderproto xextproto inputproto \
		videoproto compositeproto recordproto \
		fontsproto resourceproto xf86driproto glproto \
		presentproto xineramaproto xkbfile xfont

OPTIONS_EXCLUDE=	SUID HAL DEVD

SLAVE_PORT=	yes
PLIST_FILES=	bin/Xvfb \
		man/man1/Xvfb.1.gz

do-install:
	cd ${WRKSRC}/hw/vfb; DESTDIR=${STAGEDIR} ${MAKE} install

.include "${MASTERDIR}/Makefile"
