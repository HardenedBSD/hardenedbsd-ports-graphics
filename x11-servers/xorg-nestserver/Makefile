# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xorg-nestserver

COMMENT=	Nesting X server from X.Org

LIB_DEPENDS=	libxcb-keysyms.so:x11/xcb-util-keysyms

 	 
MASTERDIR=	${.CURDIR}/../xorg-server
DESCR=		${.CURDIR}/pkg-descr

CONFIGURE_ARGS= --disable-dmx \
		--disable-xephyr \
		--enable-xnest \
		--disable-xfbdev \
		--disable-kdrive \
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
		--disable-xvfb \
		--with-fontrootdir=${PREFIX}/share/fonts

USE_XORG=	x11 xf86driproto glproto randrproto renderproto fixesproto \
		damageproto xcmiscproto xextproto xf86miscproto inputproto \
		xf86vidmodeproto xf86bigfontproto scrnsaverproto bigreqsproto \
		dri2proto resourceproto fontsproto xf86dgaproto videoproto \
		compositeproto trapproto recordproto resourceproto \
		xineramaproto xinerama evieproto xkbfile xfont fontenc xkbui \
		xxf86misc xxf86vm xaw7 xmu xpm xext pixman xtrans presentproto

OPTIONS_EXCLUDE=	HAL SUID DEVD

SLAVE_PORT=	yes
PLIST_FILES=	bin/Xnest \
		man/man1/Xnest.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hw/xnest/Xnest ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/hw/xnest/man/Xnest.1 ${STAGEDIR}${PREFIX}/man/man1/

.include "${MASTERDIR}/Makefile"
