/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Screen1ViewBase::Screen1ViewBase() :
    flexButtonCallback(this, &Screen1ViewBase::flexButtonCallbackHandler)
{
    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    image1.setXY(0, 0);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_DARK_THEME_IMAGES_BACKGROUNDS_480X272_ASPHALT_ID));
    add(image1);

    scalableImagePin.setBitmap(touchgfx::Bitmap(BITMAP_DARK_THEME_IMAGES_CONTAINERS_LARGE_NARROW_LIGHT_ID));
    scalableImagePin.setPosition(130, 32, 220, 52);
    scalableImagePin.setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);
    add(scalableImagePin);

    button1.setBoxWithBorderPosition(0, 0, 50, 50);
    button1.setBorderSize(5);
    button1.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    button1.setAction(flexButtonCallback);
    button1.setPosition(148, 93, 50, 50);
    add(button1);

    button2.setBoxWithBorderPosition(0, 0, 50, 50);
    button2.setBorderSize(5);
    button2.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    button2.setAction(flexButtonCallback);
    button2.setPosition(214, 93, 50, 50);
    add(button2);

    button3.setBoxWithBorderPosition(0, 0, 50, 50);
    button3.setBorderSize(5);
    button3.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    button3.setAction(flexButtonCallback);
    button3.setPosition(280, 93, 50, 50);
    add(button3);

    button4.setBoxWithBorderPosition(0, 0, 50, 50);
    button4.setBorderSize(5);
    button4.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    button4.setAction(flexButtonCallback);
    button4.setPosition(149, 155, 50, 50);
    add(button4);

    button5.setBoxWithBorderPosition(0, 0, 50, 50);
    button5.setBorderSize(5);
    button5.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    button5.setAction(flexButtonCallback);
    button5.setPosition(215, 155, 50, 50);
    add(button5);

    button6.setBoxWithBorderPosition(0, 0, 50, 50);
    button6.setBorderSize(5);
    button6.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    button6.setAction(flexButtonCallback);
    button6.setPosition(280, 155, 50, 50);
    add(button6);

    button7.setBoxWithBorderPosition(0, 0, 50, 50);
    button7.setBorderSize(5);
    button7.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    button7.setAction(flexButtonCallback);
    button7.setPosition(149, 214, 50, 50);
    add(button7);

    button8.setBoxWithBorderPosition(0, 0, 50, 50);
    button8.setBorderSize(5);
    button8.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    button8.setAction(flexButtonCallback);
    button8.setPosition(215, 214, 50, 50);
    add(button8);

    button9.setBoxWithBorderPosition(0, 0, 50, 50);
    button9.setBorderSize(5);
    button9.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    button9.setAction(flexButtonCallback);
    button9.setPosition(280, 214, 50, 50);
    add(button9);

    buttonActivate.setBoxWithBorderPosition(0, 0, 232, 77);
    buttonActivate.setBorderSize(5);
    buttonActivate.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(153, 48, 0), touchgfx::Color::getColorFromRGB(204, 65, 0), touchgfx::Color::getColorFromRGB(84, 33, 11), touchgfx::Color::getColorFromRGB(153, 54, 8));
    buttonActivate.setVisible(false);
    buttonActivate.setAction(flexButtonCallback);
    buttonActivate.setPosition(117, 142, 232, 77);
    add(buttonActivate);

    textAreaActivate.setXY(137, 168);
    textAreaActivate.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textAreaActivate.setLinespacing(0);
    textAreaActivate.setTypedText(touchgfx::TypedText(T___SINGLEUSE_E7OF));
    textAreaActivate.setVisible(false);
    add(textAreaActivate);

    textArea1.setXY(167, 106);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_MFQA));
    add(textArea1);

    textArea6.setXY(299, 168);
    textArea6.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea6.setLinespacing(0);
    textArea6.setTypedText(touchgfx::TypedText(T___SINGLEUSE_QDCW));
    add(textArea6);

    textArea2.setXY(234, 106);
    textArea2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea2.setLinespacing(0);
    textArea2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_IY11));
    add(textArea2);

    textArea3.setXY(299, 106);
    textArea3.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea3.setLinespacing(0);
    textArea3.setTypedText(touchgfx::TypedText(T___SINGLEUSE_24H2));
    add(textArea3);

    textArea4.setXY(167, 168);
    textArea4.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea4.setLinespacing(0);
    textArea4.setTypedText(touchgfx::TypedText(T___SINGLEUSE_6Y68));
    add(textArea4);

    textArea5.setXY(234, 168);
    textArea5.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea5.setLinespacing(0);
    textArea5.setTypedText(touchgfx::TypedText(T___SINGLEUSE_979J));
    add(textArea5);

    textArea7.setXY(168, 227);
    textArea7.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea7.setLinespacing(0);
    textArea7.setTypedText(touchgfx::TypedText(T___SINGLEUSE_P3XV));
    add(textArea7);

    textArea8.setXY(234, 227);
    textArea8.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea8.setLinespacing(0);
    textArea8.setTypedText(touchgfx::TypedText(T___SINGLEUSE_QZL5));
    add(textArea8);

    textArea9.setXY(299, 227);
    textArea9.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea9.setLinespacing(0);
    textArea9.setTypedText(touchgfx::TypedText(T___SINGLEUSE_N207));
    add(textArea9);

    textAreaCountdownAlarmSet.setXY(208, 45);
    textAreaCountdownAlarmSet.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textAreaCountdownAlarmSet.setLinespacing(0);
    Unicode::snprintf(textAreaCountdownAlarmSetBuffer, TEXTAREACOUNTDOWNALARMSET_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_7BTU).getText());
    textAreaCountdownAlarmSet.setWildcard(textAreaCountdownAlarmSetBuffer);
    textAreaCountdownAlarmSet.resizeToCurrentText();
    textAreaCountdownAlarmSet.setTypedText(touchgfx::TypedText(T___SINGLEUSE_RS7Z));
    textAreaCountdownAlarmSet.setVisible(false);
    add(textAreaCountdownAlarmSet);

    imagePolice.setXY(391, 36);
    imagePolice.setBitmap(touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_MAPS_LOCAL_POLICE_48_48_FFD000_SVG_ID));
    imagePolice.setVisible(false);
    add(imagePolice);

    textAreaPin.setPosition(148, 43, 182, 30);
    textAreaPin.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaPin.setLinespacing(0);
    Unicode::snprintf(textAreaPinBuffer, TEXTAREAPIN_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_7FZJ).getText());
    textAreaPin.setWildcard(textAreaPinBuffer);
    textAreaPin.setTypedText(touchgfx::TypedText(T___SINGLEUSE_PDPH));
    add(textAreaPin);

    imageError.setXY(211, 35);
    imageError.setBitmap(touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_ALERT_ERROR_OUTLINE_46_46_B84040_SVG_ID));
    imageError.setVisible(false);
    add(imageError);

    textAreaCountdownOngoingAlarmSet.setXY(390, 33);
    textAreaCountdownOngoingAlarmSet.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textAreaCountdownOngoingAlarmSet.setLinespacing(0);
    Unicode::snprintf(textAreaCountdownOngoingAlarmSetBuffer, TEXTAREACOUNTDOWNONGOINGALARMSET_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_SLOD).getText());
    textAreaCountdownOngoingAlarmSet.setWildcard(textAreaCountdownOngoingAlarmSetBuffer);
    textAreaCountdownOngoingAlarmSet.resizeToCurrentText();
    textAreaCountdownOngoingAlarmSet.setTypedText(touchgfx::TypedText(T___SINGLEUSE_BFLD));
    textAreaCountdownOngoingAlarmSet.setVisible(false);
    add(textAreaCountdownOngoingAlarmSet);

    buttonPreventActivation.setBoxWithBorderPosition(0, 0, 232, 77);
    buttonPreventActivation.setBorderSize(5);
    buttonPreventActivation.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(153, 0, 0), touchgfx::Color::getColorFromRGB(204, 0, 0), touchgfx::Color::getColorFromRGB(102, 0, 0), touchgfx::Color::getColorFromRGB(153, 52, 52));
    buttonPreventActivation.setVisible(false);
    buttonPreventActivation.setAction(flexButtonCallback);
    buttonPreventActivation.setPosition(117, 142, 232, 77);
    add(buttonPreventActivation);

    textAreaPreventActivation.setXY(190, 168);
    textAreaPreventActivation.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textAreaPreventActivation.setLinespacing(0);
    textAreaPreventActivation.setTypedText(touchgfx::TypedText(T___SINGLEUSE_W1ZN));
    textAreaPreventActivation.setVisible(false);
    add(textAreaPreventActivation);
}

Screen1ViewBase::~Screen1ViewBase()
{

}

void Screen1ViewBase::setupScreen()
{

}

void Screen1ViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &buttonActivate)
    {
        //activateAlarmSystem
        //When buttonActivate clicked call virtual function
        //Call activateAlarmSystem
        activateAlarmSystem();
    }
    if (&src == &button1)
    {
        //clickButton1
        //When button1 clicked call virtual function
        //Call clickButton1
        clickButton1();
    }
    if (&src == &button2)
    {
        //clickButton2
        //When button2 clicked call virtual function
        //Call clickButton2
        clickButton2();
    }
    if (&src == &button3)
    {
        //clickButton3
        //When button3 clicked call virtual function
        //Call clickButton3
        clickButton3();
    }
    if (&src == &button4)
    {
        //clickButton4
        //When button4 clicked call virtual function
        //Call clickButton4
        clickButton4();
    }
    if (&src == &button5)
    {
        //clickButton5
        //When button5 clicked call virtual function
        //Call clickButton5
        clickButton5();
    }
    if (&src == &button6)
    {
        //clickButton6
        //When button6 clicked call virtual function
        //Call clickButton6
        clickButton6();
    }
    if (&src == &button7)
    {
        //clickButton7
        //When button7 clicked call virtual function
        //Call clickButton7
        clickButton7();
    }
    if (&src == &button8)
    {
        //clickButton8
        //When button8 clicked call virtual function
        //Call clickButton8
        clickButton8();
    }
    if (&src == &button9)
    {
        //clickButton9
        //When button9 clicked call virtual function
        //Call clickButton9
        clickButton9();
    }
    if (&src == &buttonPreventActivation)
    {
        //preventActivationAlarmSystem
        //When buttonPreventActivation clicked call virtual function
        //Call preventActivationAlarmSystem
        preventActivationAlarmSystem();
    }
}
