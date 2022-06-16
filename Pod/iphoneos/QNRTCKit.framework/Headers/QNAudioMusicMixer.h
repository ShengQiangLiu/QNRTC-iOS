//
//  QNAudioMusicMixer.h
//  QNRTCKit
//
//  Created by 冯文秀 on 2022/4/8.
//  Copyright © 2022 Pili Engineering, Qiniu Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QNTypeDefines.h"

NS_ASSUME_NONNULL_BEGIN

@class QNAudioMusicMixer;

@protocol QNAudioMusicMixerDelegate <NSObject>

/*!
 * @abstract 背景音乐混音发生错误的回调
 *
 * @param audioMusicMixer 背景音乐混音实例
 *
 * @param error 错误
 *
 * @since v5.1.0
 */
- (void)audioMusicMixer:(QNAudioMusicMixer *)audioMusicMixer didFailWithError:(NSError *)error;

/*!
 * @abstract 背景音乐混音状态变化的回调
 *
 * @param audioMusicMixer 背景音乐混音实例
 *
 * @param musicMixerState 背景音乐混音回调代理
 *
 * @since v5.1.0
 */
- (void)audioMusicMixer:(QNAudioMusicMixer *)audioMusicMixer didStateChanged:(QNAudioMusicMixerState)musicMixerState;

/*!
 * @abstract 背景音乐混音当前进度的回调
 *
 * @param audioMusicMixer 背景音乐混音实例
 *
 * @param currentPosition 当前进度
 *
 * @discussion 需要注意的是这个回调在解码线程，请不要做过于耗时的操作，否则可能阻塞该线程影响音频输出或其他未知问题。
 *
 * @since v5.1.0
 */
- (void)audioMusicMixer:(QNAudioMusicMixer *)audioMusicMixer didMixing:(int64_t)currentPosition;

@end


@interface QNAudioMusicMixer : NSObject

/*!
 * @abstract 获取指定音频文件的总时长
 *
 * @param filePath 文件路径，支持本地路径以及在线文件
 *
 * @return int64_t 总时长，单位 ms
 *
 * @since v5.1.0
 */
+ (int64_t)getDuration:(NSString *)filePath;

/*!
 * @abstract 设置参与混音的音量
 *
 * @param volume 音量，范围 0～1.0
 *
 * @since v5.1.0
 */
- (void)setMixingVolume:(float)volume;

/*!
 * @abstract 获取参与混音的音量
 *
 * @return float 音量，范围 0～1.0
 *
 * @since v5.1.0
 */
- (float)getMixingVolume;

/*!
 * @abstract 设置参与混音的起始位置
 *
 * @param position 位置，单位 ms
 *
 * @since v5.1.0
 */
- (void)setStartPosition:(int64_t)position;

/*!
 * @abstract 获取参与混音的起始位置
 *
 * @return int64_t 单位 ms
 *
 * @since v5.1.0
 */
- (int64_t)getStartPosition;

/*!
 * @abstract 获取当前时长
 *
 * @return int64_t 单位 ms
 *
 * @since v5.1.0
 */
- (int64_t)getCurrentPosition;

/*!
 * @abstract 开始混音，默认混一次
 *
 * @return BOOL 是否成功
 *
 * @since v5.1.0
 */
- (BOOL)start;

/*!
 * @abstract 开始混音，可设置循环次数
 *
 * @param loopCount 循环次数，-1 为无限循环，0 为不混音，大于 0 为实际循环次数
 *
 * @return BOOL 是否成功
 *
 * @since v5.1.0
 */
- (BOOL)start:(int)loopCount;


/*!
 * @abstract 停止混音
 *
 * @return BOOL 是否成功
 *
 * @since v5.1.0
 */
- (BOOL)stop;

/*!
 * @abstract 暂停混音
 *
 * @return BOOL 是否成功
 *
 * @since v5.1.0
 */
- (BOOL)pause;

/*!
 * @abstract 恢复混音
 *
 * @return BOOL 是否成功
 *
 * @since v5.1.0
 */
- (BOOL)resume;

/*!
 * @abstract 跳转
 *
 * @param position 跳转的位置，单位 ms
 *
 * @return BOOL 是否成功
 *
 * @since v5.1.0
 */
- (BOOL)seekTo:(int64_t)position;

@end

NS_ASSUME_NONNULL_END