# QNRTCKit Release Notes for 5.2.2

## 内容

- [简介](#简介)
- [问题反馈](#问题反馈)
- [记录](#记录)

## 简介

QNRTCKit 是七牛推出的一款适用于 iOS 平台的音视频通话 SDK，提供了包括美颜、滤镜、水印、音视频通话等多种功能，提供灵活的接口，支持高度定制以及二次开发。


## 记录

- 缺陷
	- 修复在重连失败再次加入房间后，离开房间会崩溃的问题
	- 修复采集分辨率和编码分辨率不一致，导致画面被裁剪的问题  

- 优化
	- 优化在 RTT 一定波动网络环境下视频卡顿的现象

## 问题反馈

当你遇到任何问题时，可以通过在 GitHub 的 repo 提交 ```issues``` 来反馈问题，请尽可能的描述清楚遇到的问题，如果有错误信息也一同附带，并且在 ```Labels``` 中指明类型为 bug 或者其他。

[通过这里查看已有的 issues 和提交 bug](https://github.com/pili-engineering/QNRTC-iOS/issues)