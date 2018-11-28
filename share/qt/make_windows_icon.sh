#!/bin/bash
# create multiresolution windows icon
ICON_DST=../../src/qt/res/icons/Zong.ico

convert ../../src/qt/res/icons/Zong-16.png ../../src/qt/res/icons/Zong-32.png ../../src/qt/res/icons/Zong-48.png ${ICON_DST}
