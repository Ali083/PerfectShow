#ifndef VENUS_EFFECT_H_
#define VENUS_EFFECT_H_

#include <opencv2/core.hpp>

namespace venus {

enum class RangeMode
{
	SHADOWS,
	MIDTONES,
	HIGHLIGHTS,
};
class Effect
{
private:
	static float mapColorBalance(float value, float lightness, float shadows, float midtones, float highlights);

public:
	static void mapColor(cv::Mat& dst, const cv::Mat&src, const uint8_t table[256]);
	static void mapColor(cv::Mat& dst, const cv::Mat&src, const uint8_t* mask, const uint8_t table[256]);
	/**
	 * Tone is a color term commonly used by painters. Toning a bitmap with specified color, it's 
	 * like mixing the color pixel by pixel, the color resulting in layering a color 
	 * <code>dst</code> RGB with a <code>src</code> color RGB is:
	 * 
	 * <pre>
	 * new_R = dst_R + (src_R - dst_R) * amount
	 * new_G = dst_G + (src_G - dst_G) * amount
	 * new_B = dst_B + (src_B - dst_B) * amount
	 * </pre>
	 * 
	 * @see {@link https://en.wikipedia.org/wiki/Tints_and_shades}
	 * 
	 * @param[out] dst
	 * @param[in]  src
	 * @param[in]  color  RGBA memory layout
	 * @param[in]  amount Color blending amount, with 0 being unchanged, with 1 being the pure color.
	 * @return
	 */
	static void tone(cv::Mat& dst, const cv::Mat& src, uint32_t color, float amount);

	// "inline static" vs "static inline" https://lwn.net/Articles/142278/
	static inline void shade(cv::Mat& dst, const cv::Mat& src, float amount)   { tone(dst, src, 0x00000000/* black */, amount); }
	static inline void tint (cv::Mat& dst, const cv::Mat& src, float amount)   { tone(dst, src, 0x00FFFFFF/* white */, amount); }
	static inline void tone (cv::Mat& dst, const cv::Mat& src, uint32_t color) { tone(dst, src, color, (color>>24)/255.0F);     }

	/**
	 * <a href="https://en.wikipedia.org/wiki/Posterization">Posterization</a> of an image entails conversion of a continuous gradation of
	 * tone to several regions of fewer tones, with abrupt changes from one tone to another. This was originally done with photographic
	 * processes to create posters.
	 *
	 * @param[out] dst    The output image, and in-place posterizing is supported.
	 * @param[in]  src    The input image.
	 * @param[in]  level  Range [1.0, 256.0], and value 256 means copy @a src to @a dst.
	 */
	static void posterize(cv::Mat& dst, const cv::Mat& src, float level);

	/**
	 * Convert a color image into grayscale image.
	 *
	 * @param[in] image The color image.
	 * @return a grayscale image.
	 */
	static cv::Mat grayscale(const cv::Mat& image);

	/**
	 * Note that @p dst can be same as @p src image.
	 *
	 * @param[out] dst    The output image.
	 * @param[in]  src    The input image.
	 * @param[in]  radius Blur radius.
	 */
	static void gaussianBlur(cv::Mat& dst, const cv::Mat& src, float radius);
	inline static void gaussianBlur(cv::Mat& image, float radius) { gaussianBlur(image, image, radius); }

	/**
	 *  Large filters (radius > 5) are very slow, so it is recommended to use radius = 3 for real-time applications,
	 */
	static void selectiveGaussianBlur(cv::Mat& dst, const cv::Mat& src, float radius, float tolerance);
	inline static void selectiveGaussianBlur(cv::Mat& image, float radius, float tolerance) { selectiveGaussianBlur(image, image, radius, tolerance); }

	/**
	 * color balance is the global adjustment of the intensities of the colors (typically red, green, and blue primary colors).
	 * @see https://en.wikipedia.org/wiki/Color_balance for details.
	 *
	 * @param[out] dst
	 * @param[in]  src
	 * @param[in]  config Array of {shadows, midtones, highlights}, each RangeMode is a Vec3f(CYAN_RED, MAGENTA_GREEN, YELLOW_BLUE)
	 *                    each channel is in range [-1.0, 1.0].
	 * @param[in] preserve_luminosity
	 */
	static void adjustColorBalance(float* const dst, const float* const src, int width, int height, const cv::Vec3f config[3], bool preserve_luminosity);
//	static void adjustColorBalance(uint8_t* const dst, const uint8_t* const src, int width, int height, const cv::Vec3f config[3], bool preserve_luminosity);
//	static void adjustColorBalance(cv::Mat& dst, const cv::Mat& src, const cv::Vec3f config[3], bool preserve_luminosity);
	
	/**
	 * https://en.wikipedia.org/wiki/Gamma_correction,  In NTSC television recording, γ = 2.2
	 *
	 * @param[out] dst    The resulting image, can be the same as input image.
	 * @param[in]  src    The input image to operate on.
	 * @param[in]  gamma  A positive value, with value 1 being unchanged, γ < 1 for encoding (gamma compression),
	 *                    γ > 1 for decoding (gamma expansion).
	 */
	static void adjustGamma(cv::Mat& dst, const cv::Mat& src, float gamma);

	/**
	 * It's the same as @ref adjustGamma(cv::Mat&, const cv::Mat&, float) except that this works on different gamma values for RGB channels.
	 * It gives a fine-grain control on seperate channels.
	 *
	 * @copydoc adjustGamma(cv::Mat&, const cv::Mat&, float)
	 */
	static void adjustGamma(cv::Mat& dst, const cv::Mat& src, const cv::Vec3f& gamma);
};

} /* namespace venus */
#endif /* VENUS_EFFECT_H_ */
