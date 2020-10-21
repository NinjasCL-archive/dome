/**
 * 8x8 monochrome bitmap fonts for rendering
 * Author: Daniel Hepper <daniel@hepper.net>
 *
 * License: Public Domain
 *
 * Based on:
 * // Summary: font8x8.h
 * // 8x8 monochrome bitmap fonts for rendering
 * //
 * // Author:
 * //     Marcel Sondaar
 * //     International Business Machines (public domain VGA fonts)
 * //
 * // License:
 * //     Public Domain
 *
 * Fetched from: http://dimensionalrift.homelinux.net/combuster/mos3/?p=viewsource&file=/modules/gfx/font8_8.asm
 **/

// Constant: font8x8_2500
// Contains an 8x8 font map for unicode points U+2500 - U+257F (box drawing)
unsigned char font8x8_box[128][8] = {
    { 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00},   // U+2500 (thin horizontal)
    { 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00},   // U+2501 (thick horizontal)
    { 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08},   // U+2502 (thin vertical)
    { 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18},   // U+2503 (thich vertical)
    { 0x00, 0x00, 0x00, 0x00, 0xBB, 0x00, 0x00, 0x00},   // U+2504 (thin horizontal dashed)
    { 0x00, 0x00, 0x00, 0xBB, 0xBB, 0x00, 0x00, 0x00},   // U+2505 (thick horizontal dashed)
    { 0x08, 0x00, 0x08, 0x08, 0x08, 0x00, 0x08, 0x08},   // U+2506 (thin vertical dashed)
    { 0x18, 0x00, 0x18, 0x18, 0x18, 0x00, 0x18, 0x18},   // U+2507 (thich vertical dashed)
    { 0x00, 0x00, 0x00, 0x00, 0x55, 0x00, 0x00, 0x00},   // U+2508 (thin horizontal dotted)
    { 0x00, 0x00, 0x00, 0x55, 0x55, 0x00, 0x00, 0x00},   // U+2509 (thick horizontal dotted)
    { 0x00, 0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 0x08},   // U+250A (thin vertical dotted)
    { 0x00, 0x18, 0x00, 0x18, 0x00, 0x18, 0x00, 0x18},   // U+250B (thich vertical dotted)
    { 0x00, 0x00, 0x00, 0x00, 0xf8, 0x08, 0x08, 0x08},   // U+250C (down L, right L)
    { 0x00, 0x00, 0x00, 0xf8, 0xf8, 0x08, 0x08, 0x08},   // U+250D (down L, right H)
    { 0x00, 0x00, 0x00, 0x00, 0xf8, 0x18, 0x18, 0x18},   // U+250E (down H, right L)
    { 0x00, 0x00, 0x00, 0xf8, 0xf8, 0x18, 0x18, 0x18},   // U+250F (down H, right H)
    { 0x00, 0x00, 0x00, 0x00, 0x0f, 0x08, 0x08, 0x08},   // U+2510 (down L, left L)
    { 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x08, 0x08, 0x08},   // U+2511 (down L, left H)
    { 0x00, 0x00, 0x00, 0x00, 0x1f, 0x18, 0x18, 0x18},   // U+2512 (down H, left L)
    { 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x18, 0x18, 0x18},   // U+2513 (down H, left H)
    { 0x08, 0x08, 0x08, 0x08, 0xf8, 0x00, 0x00, 0x00},   // U+2514 (up L, right L)
    { 0x08, 0x08, 0x08, 0xf8, 0xf8, 0x00, 0x00, 0x00},   // U+2515 (up L, right H)
    { 0x18, 0x18, 0x18, 0x18, 0xf8, 0x00, 0x00, 0x00},   // U+2516 (up H, right L)
    { 0x18, 0x18, 0x18, 0xf8, 0xf8, 0x00, 0x00, 0x00},   // U+2517 (up H, right H)
    { 0x08, 0x08, 0x08, 0x08, 0x0f, 0x00, 0x00, 0x00},   // U+2518 (up L, left L)
    { 0x08, 0x08, 0x08, 0x0f, 0x0f, 0x00, 0x00, 0x00},   // U+2519 (up L, left H)
    { 0x18, 0x18, 0x18, 0x18, 0x1f, 0x00, 0x00, 0x00},   // U+251A (up H, left L)
    { 0x18, 0x18, 0x18, 0x1f, 0x1f, 0x00, 0x00, 0x00},   // U+251B (up H, left H)
    { 0x08, 0x08, 0x08, 0x08, 0xf8, 0x08, 0x08, 0x08},   // U+251C (down L, right L, up L)
    { 0x08, 0x08, 0x08, 0xf8, 0xf8, 0x08, 0x08, 0x08},   // U+251D (down L, right H, up L)
    { 0x18, 0x18, 0x18, 0x18, 0xf8, 0x08, 0x08, 0x08},   // U+251E (down L, right L, up H)
    { 0x08, 0x08, 0x08, 0x08, 0xf8, 0x18, 0x18, 0x18},   // U+251F (down H, right L, up L)
    { 0x18, 0x18, 0x18, 0x18, 0xf8, 0x18, 0x18, 0x18},   // U+2520 (down H, right L, up H)
    { 0x18, 0x18, 0x18, 0xf8, 0xf8, 0x08, 0x08, 0x08},   // U+2521 (down L, right H, up H)
    { 0x08, 0x08, 0x08, 0xf8, 0xf8, 0x18, 0x18, 0x18},   // U+2522 (down H, right H, up L)
    { 0x18, 0x18, 0x18, 0xf8, 0xf8, 0x18, 0x18, 0x18},   // U+2523 (down H, right H, up H)
    { 0x08, 0x08, 0x08, 0x08, 0x0f, 0x08, 0x08, 0x08},   // U+2524 (down L, left L, up L)
    { 0x08, 0x08, 0x08, 0x0f, 0x0f, 0x08, 0x08, 0x08},   // U+2525 (down L, left H, up L)
    { 0x18, 0x18, 0x18, 0x18, 0x1f, 0x08, 0x08, 0x08},   // U+2526 (down L, left L, up H)
    { 0x08, 0x08, 0x08, 0x08, 0x1f, 0x18, 0x18, 0x18},   // U+2527 (down H, left L, up L)
    { 0x18, 0x18, 0x18, 0x18, 0x1f, 0x18, 0x18, 0x18},   // U+2528 (down H, left L, up H)
    { 0x18, 0x18, 0x18, 0x1f, 0x1f, 0x08, 0x08, 0x08},   // U+2529 (down L, left H, up H)
    { 0x08, 0x08, 0x08, 0x1f, 0x1f, 0x18, 0x18, 0x18},   // U+252A (down H, left H, up L)
    { 0x18, 0x18, 0x18, 0x1f, 0x1f, 0x18, 0x18, 0x18},   // U+252B (down H, left H, up H)
    { 0x00, 0x00, 0x00, 0x00, 0xff, 0x08, 0x08, 0x08},   // U+252C (down L, right L, left L)
    { 0x00, 0x00, 0x00, 0x0f, 0xff, 0x08, 0x08, 0x08},   // U+252D (down L, right L, left H)
    { 0x00, 0x00, 0x00, 0xf8, 0xff, 0x08, 0x08, 0x08},   // U+252E (down L, right H, left L)
    { 0x00, 0x00, 0x00, 0xff, 0xff, 0x08, 0x08, 0x08},   // U+252F (down L, right H, left H)
    { 0x00, 0x00, 0x00, 0x00, 0xff, 0x18, 0x18, 0x18},   // U+2530 (down H, right L, left L)
    { 0x00, 0x00, 0x00, 0x1f, 0xff, 0x18, 0x18, 0x18},   // U+2531 (down H, right L, left H)
    { 0x00, 0x00, 0x00, 0xf8, 0xff, 0x18, 0x18, 0x18},   // U+2532 (down H, right H, left L)
    { 0x00, 0x00, 0x00, 0xff, 0xff, 0x18, 0x18, 0x18},   // U+2533 (down H, right H, left H)
    { 0x08, 0x08, 0x08, 0x08, 0xff, 0x00, 0x00, 0x00},   // U+2534 (up L, right L, left L)
    { 0x08, 0x08, 0x08, 0x0f, 0xff, 0x00, 0x00, 0x00},   // U+2535 (up L, right L, left H)
    { 0x08, 0x08, 0x08, 0xf8, 0xff, 0x00, 0x00, 0x00},   // U+2536 (up L, right H, left L)
    { 0x08, 0x08, 0x08, 0xff, 0xff, 0x00, 0x00, 0x00},   // U+2537 (up L, right H, left H)
    { 0x18, 0x18, 0x18, 0x18, 0xff, 0x00, 0x00, 0x00},   // U+2538 (up H, right L, left L)
    { 0x18, 0x18, 0x18, 0x1f, 0xff, 0x00, 0x00, 0x00},   // U+2539 (up H, right L, left H)
    { 0x18, 0x18, 0x18, 0xf8, 0xff, 0x00, 0x00, 0x00},   // U+253A (up H, right H, left L)
    { 0x18, 0x18, 0x18, 0xff, 0xff, 0x00, 0x00, 0x00},   // U+253B (up H, right H, left H)
    { 0x08, 0x08, 0x08, 0x08, 0xff, 0x08, 0x08, 0x08},   // U+253C (up L, right L, left L, down L)
    { 0x08, 0x08, 0x08, 0x0f, 0xff, 0x08, 0x08, 0x08},   // U+253D (up L, right L, left H, down L)
    { 0x08, 0x08, 0x08, 0xf8, 0xff, 0x08, 0x08, 0x08},   // U+253E (up L, right H, left L, down L)
    { 0x08, 0x08, 0x08, 0xff, 0xff, 0x08, 0x08, 0x08},   // U+253F (up L, right H, left H, down L)
    { 0x18, 0x18, 0x18, 0x18, 0xff, 0x08, 0x08, 0x08},   // U+2540 (up H, right L, left L, down L)
    { 0x08, 0x08, 0x08, 0x08, 0xff, 0x18, 0x18, 0x18},   // U+2541 (up L, right L, left L, down H)
    { 0x18, 0x18, 0x18, 0x18, 0xff, 0x18, 0x18, 0x18},   // U+2542 (up H, right L, left L, down H)
    { 0x18, 0x18, 0x18, 0x1f, 0xff, 0x08, 0x08, 0x08},   // U+2543 (up H, right L, left H, down L)
    { 0x18, 0x18, 0x18, 0xf8, 0xff, 0x08, 0x08, 0x08},   // U+2544 (up H, right H, left L, down L)
    { 0x08, 0x08, 0x08, 0x1f, 0xff, 0x18, 0x18, 0x18},   // U+2545 (up L, right L, left H, down H)
    { 0x08, 0x08, 0x08, 0xf8, 0xff, 0x18, 0x18, 0x18},   // U+2546 (up L, right H, left L, down H)
    { 0x08, 0x08, 0x08, 0xff, 0xff, 0x18, 0x18, 0x18},   // U+2547 (up L, right H, left H, down H)
    { 0x18, 0x18, 0x18, 0xff, 0xff, 0x08, 0x08, 0x08},   // U+254B (up H, right H, left H, down L)
    { 0x18, 0x18, 0x18, 0xf8, 0xff, 0x18, 0x18, 0x18},   // U+254A (up H, right H, left L, down H)
    { 0x18, 0x18, 0x18, 0x1f, 0xff, 0x18, 0x18, 0x18},   // U+2549 (up H, right L, left H, down H)
    { 0x18, 0x18, 0x18, 0xff, 0xff, 0x18, 0x18, 0x18},   // U+254B (up H, right H, left H, down H)
    { 0x00, 0x00, 0x00, 0x00, 0xE7, 0x00, 0x00, 0x00},   // U+254C (thin horizontal broken)
    { 0x00, 0x00, 0x00, 0xE7, 0xE7, 0x00, 0x00, 0x00},   // U+254D (thick horizontal broken)
    { 0x08, 0x08, 0x08, 0x00, 0x00, 0x08, 0x08, 0x08},   // U+254E (thin vertical broken)
    { 0x18, 0x18, 0x18, 0x00, 0x00, 0x18, 0x18, 0x18},   // U+254F (thich vertical broken)
    { 0x00, 0x00, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x00},   // U+2550 (double horizontal)
    { 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14},   // U+2551 (double vertical)
    { 0x00, 0x00, 0x00, 0xF8, 0x08, 0xF8, 0x08, 0x08},   // U+2552 (down L, right D)
    { 0x00, 0x00, 0x00, 0x00, 0xFC, 0x14, 0x14, 0x14},   // U+2553 (down D, right L)
    { 0x00, 0x00, 0x00, 0xFC, 0x04, 0xF4, 0x14, 0x14},   // U+2554 (down D, right D)
    { 0x00, 0x00, 0x00, 0x0F, 0x08, 0x0F, 0x08, 0x08},   // U+2555 (down L, left D)
    { 0x00, 0x00, 0x00, 0x00, 0x1F, 0x14, 0x14, 0x14},   // U+2556 (down D, left L)
    { 0x00, 0x00, 0x00, 0x1F, 0x10, 0x17, 0x14, 0x14},   // U+2557 (down D, left D)
    { 0x08, 0x08, 0x08, 0xF8, 0x08, 0xF8, 0x00, 0x00},   // U+2558 (up L, right D)
    { 0x14, 0x14, 0x14, 0x14, 0xFC, 0x00, 0x00, 0x00},   // U+2559 (up D, right L)
    { 0x14, 0x14, 0x14, 0xF4, 0x04, 0xFC, 0x00, 0x00},   // U+255A (up D, right D)
    { 0x08, 0x08, 0x08, 0x0F, 0x08, 0x0F, 0x00, 0x00},   // U+255B (up L, left D)
    { 0x14, 0x14, 0x14, 0x14, 0x1F, 0x00, 0x00, 0x00},   // U+255C (up D, left L)
    { 0x14, 0x14, 0x14, 0x17, 0x10, 0x1F, 0x00, 0x00},   // U+255D (up D, left D)
    { 0x08, 0x08, 0x08, 0xF8, 0x08, 0xF8, 0x08, 0x08},   // U+255E (up L, down L, right D)
    { 0x14, 0x14, 0x14, 0x14, 0xF4, 0x14, 0x14, 0x14},   // U+255F (up D, down D, right L)
    { 0x14, 0x14, 0x14, 0xF4, 0x04, 0xF4, 0x14, 0x14},   // U+2560 (up D, down D, right D)
    { 0x08, 0x08, 0x08, 0x0F, 0x08, 0x0F, 0x08, 0x08},   // U+2561 (up L, down L, left D)
    { 0x14, 0x14, 0x14, 0x14, 0x17, 0x14, 0x14, 0x14},   // U+2562 (up D, down D, left L)
    { 0x14, 0x14, 0x14, 0x17, 0x10, 0x17, 0x14, 0x14},   // U+2563 (up D, down D, left D)
    { 0x00, 0x00, 0x00, 0xFF, 0x00, 0xFF, 0x08, 0x08},   // U+2564 (left D, right D, down L)
    { 0x00, 0x00, 0x00, 0x00, 0xFF, 0x14, 0x14, 0x14},   // U+2565 (left L, right L, down D)
    { 0x00, 0x00, 0x00, 0xFF, 0x00, 0xF7, 0x14, 0x14},   // U+2566 (left D, right D, down D)
    { 0x08, 0x08, 0x08, 0xFF, 0x00, 0xFF, 0x00, 0x00},   // U+2567 (left D, right D, up L)
    { 0x14, 0x14, 0x14, 0x14, 0xFF, 0x00, 0x00, 0x00},   // U+2568 (left L, right L, up D)
    { 0x14, 0x14, 0x14, 0xF7, 0x00, 0xFF, 0x00, 0x00},   // U+2569 (left D, right D, up D)
    { 0x08, 0x08, 0x08, 0xFF, 0x08, 0xFF, 0x08, 0x08},   // U+256A (left D, right D, down L, up L)
    { 0x14, 0x14, 0x14, 0x14, 0xFF, 0x14, 0x14, 0x14},   // U+256B (left L, right L, down D, up D)
    { 0x14, 0x14, 0x14, 0xF7, 0x00, 0xF7, 0x14, 0x14},   // U+256C (left D, right D, down D, up D)
    { 0x00, 0x00, 0x00, 0x00, 0xE0, 0x10, 0x08, 0x08},   // U+256D (curve down-right)
    { 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x08},   // U+256E (curve down-left)
    { 0x08, 0x08, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00},   // U+256F (curve up-left)
    { 0x08, 0x08, 0x08, 0x10, 0xE0, 0x00, 0x00, 0x00},   // U+2570 (curve up-right)
    { 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01},   // U+2571 (diagonal bottom-left to top-right)
    { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80},   // U+2572 (diagonal bottom-right to top-left)
    { 0x81, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x81},   // U+2573 (diagonal cross)
    { 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00},   // U+2574 (left L)
    { 0x08, 0x08, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00},   // U+2575 (up L)
    { 0x00, 0x00, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x00},   // U+2576 (right L)
    { 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x08, 0x08},   // U+2577 (down L)
    { 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x00, 0x00, 0x00},   // U+2578 (left H)
    { 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00},   // U+2579 (up H)
    { 0x00, 0x00, 0x00, 0xF8, 0xF8, 0x00, 0x00, 0x00},   // U+257A (right H)
    { 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0x18},   // U+257B (down H)
    { 0x00, 0x00, 0x00, 0xF8, 0xFF, 0x00, 0x00, 0x00},   // U+257C (right H, left L)
    { 0x08, 0x08, 0x08, 0x08, 0x18, 0x18, 0x18, 0x18},   // U+257D (up L, down H)
    { 0x00, 0x00, 0x00, 0x0F, 0xFF, 0x00, 0x00, 0x00},   // U+257E (right L, left H)
    { 0x18, 0x18, 0x18, 0x18, 0x08, 0x08, 0x08, 0x08}    // U+257F (up H, down L)
};
