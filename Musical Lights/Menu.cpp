//Warning produced by casting an HMENU handle to an unsigned int for use in the AppendMenu function
#pragma warning(disable : 4311)

#include "Menu.h"

Menu::Menu(System* system)
{
	system_ = system;

	REQUIRES_EITHER(
		//
		modeResponceMenu_ = CreatePopupMenu();
		AppendMenu(modeResponceMenu_, MF_STRING, TRAY_MODE_RESPONCE_HIGH_ITEM_ID, L"High"); 
		AppendMenu(modeResponceMenu_, MF_STRING, TRAY_MODE_RESPONCE_STANDARD_ITEM_ID, L"Standard"); 
		AppendMenu(modeResponceMenu_, MF_STRING, TRAY_MODE_RESPONCE_LOW_ITEM_ID, L"Low");

		//
		lightBrightnessMenu_ = CreatePopupMenu();
		AppendMenu(lightBrightnessMenu_, MF_STRING, TRAY_BRIGHTNESS_ONEHUNDRED_ITEM_ID, L"100%"); 
		AppendMenu(lightBrightnessMenu_, MF_STRING, TRAY_BRIGHTNESS_NINETY_ITEM_ID, L"90%"); 
		AppendMenu(lightBrightnessMenu_, MF_STRING, TRAY_BRIGHTNESS_EIGHTY_ITEM_ID, L"80%");
		AppendMenu(lightBrightnessMenu_, MF_STRING, TRAY_BRIGHTNESS_SEVENTY_ITEM_ID, L"70%");
		AppendMenu(lightBrightnessMenu_, MF_STRING, TRAY_BRIGHTNESS_SIXTY_ITEM_ID, L"60%");
		AppendMenu(lightBrightnessMenu_, MF_STRING, TRAY_BRIGHTNESS_FIFTY_ITEM_ID, L"50%");
		AppendMenu(lightBrightnessMenu_, MF_STRING, TRAY_BRIGHTNESS_FOURTY_ITEM_ID, L"40%");
		AppendMenu(lightBrightnessMenu_, MF_STRING, TRAY_BRIGHTNESS_THIRTY_ITEM_ID, L"30%");
		AppendMenu(lightBrightnessMenu_, MF_STRING, TRAY_BRIGHTNESS_TWENTY_ITEM_ID, L"20%");
		AppendMenu(lightBrightnessMenu_, MF_STRING, TRAY_BRIGHTNESS_TEN_ITEM_ID, L"10%");

		//
		lightingArrangementMenu_ = CreatePopupMenu();
		AppendMenu(lightingArrangementMenu_, MF_STRING, TRAY_ARRANGEMENT_STEREO_ITEM_ID, L"Stereo"); 
		AppendMenu(lightingArrangementMenu_, MF_STRING, TRAY_ARRANGEMENT_SURROUND_ITEM_ID, L"Surround"); 

		//
		REQUIRES_AURORA(
			auroraMenu_ = CreatePopupMenu();
			AppendMenu(auroraMenu_, MF_STRING, TRAY_AURORA_AVERAGE_ITEM_ID, L"Average"); 
			AppendMenu(auroraMenu_, MF_STRING, TRAY_AURORA_VIBRANT_ITEM_ID, L"Vibrant");
			AppendMenu(auroraMenu_, MF_SEPARATOR, NULL,  NULL);
			AppendMenu(auroraMenu_, MF_STRING, TRAY_AURORA_ILLUMINATE_ITEM_ID, L"Illuminate");
			AppendMenu(auroraMenu_, MF_SEPARATOR, NULL,  NULL);
			AppendMenu(auroraMenu_, MF_STRING, TRAY_AURORA_DISABLE_ITEM_ID, L"Disable");


			illuminationMenu_ = CreatePopupMenu();
			AppendMenu(illuminationMenu_, MF_STRING, TRAY_ILLUMINATION_ORIGINAL_ITEM_ID, L"Original");
			AppendMenu(illuminationMenu_, MF_STRING, TRAY_ILLUMINATION_SPECTRUM_ITEM_ID, L"Spectrum"); 
			AppendMenu(illuminationMenu_, MF_STRING, TRAY_ILLUMINATION_CANDLE_ITEM_ID, L"Candle");
			AppendMenu(illuminationMenu_, MF_STRING, TRAY_ILLUMINATION_RELAX_ITEM_ID, L"Relax");
			//AppendMenu(illuminationMenu_, MF_SEPARATOR, NULL,  NULL);
			//AppendMenu(illuminationMenu_, MF_STRING, TRAY_ILLUMINATION_CUSTOM_ITEM_ID, L"Custom");


			screenSamplingMenu_ = CreatePopupMenu();
			AppendMenu(screenSamplingMenu_, MF_STRING, TRAY_SCREEN_SAMPLING_HIGH_ITEM_ID, L"High"); 
			AppendMenu(screenSamplingMenu_, MF_STRING, TRAY_SCREEN_SAMPLING_STANDARD_ITEM_ID, L"Standard");
			AppendMenu(screenSamplingMenu_, MF_STRING, TRAY_SCREEN_SAMPLING_LOW_ITEM_ID, L"Low");


			whiteBalanceMenu_ = CreatePopupMenu();
			AppendMenu(whiteBalanceMenu_, MF_STRING, TRAY_WHITE_BALANCE_FIVE_ITEM_ID, L"5"); 
			AppendMenu(whiteBalanceMenu_, MF_STRING, TRAY_WHITE_BALANCE_FOUR_ITEM_ID, L"4");
			AppendMenu(whiteBalanceMenu_, MF_STRING, TRAY_WHITE_BALANCE_THREE_ITEM_ID, L"3");
			AppendMenu(whiteBalanceMenu_, MF_STRING, TRAY_WHITE_BALANCE_TWO_ITEM_ID, L"2");
			AppendMenu(whiteBalanceMenu_, MF_STRING, TRAY_WHITE_BALANCE_ONE_ITEM_ID, L"1");
			AppendMenu(whiteBalanceMenu_, MF_SEPARATOR, NULL,  NULL);
			AppendMenu(whiteBalanceMenu_, MF_STRING, TRAY_WHITE_BALANCE_OFF_ITEM_ID, L"0");
		);


		//
		REQUIRES_SYNESTHESIA(
			synesthesiaMenu_ = CreatePopupMenu();
			AppendMenu(synesthesiaMenu_, MF_STRING, TRAY_SYNESTHESIA_AMBIENT_ITEM_ID, L"Ambient"); 
			AppendMenu(synesthesiaMenu_, MF_STRING, TRAY_SYNESTHESIA_REACTIVE_ITEM_ID, L"Reactive");
			AppendMenu(synesthesiaMenu_, MF_SEPARATOR, NULL,  NULL);
			AppendMenu(synesthesiaMenu_, MF_STRING, TRAY_SYNESTHESIA_IMMERSIVE_ITEM_ID, L"Immersive");
			AppendMenu(synesthesiaMenu_, MF_SEPARATOR, NULL,  NULL);
			AppendMenu(synesthesiaMenu_, MF_STRING, TRAY_SYNESTHESIA_DISABLE_ITEM_ID, L"Disable");


			visualisationMenu_ = CreatePopupMenu();
			AppendMenu(visualisationMenu_, MF_STRING, TRAY_VISUALISATION_NATURAL_ITEM_ID, L"Natural"); 
			AppendMenu(visualisationMenu_, MF_STRING, TRAY_VISUALISATION_LIQUID_ITEM_ID, L"Liquid"); 
			AppendMenu(visualisationMenu_, MF_STRING, TRAY_VISUALISATION_ENERGY_ITEM_ID, L"Energy");
			//AppendMenu(visualisationMenu_, MF_SEPARATOR, NULL,  NULL);
			//AppendMenu(visualisationMenu_, MF_STRING, TRAY_VISUALISATION_CUSTOM_ITEM_ID, L"Custom");


			lightSensitivityMenu_ = CreatePopupMenu();
			AppendMenu(lightSensitivityMenu_, MF_STRING, TRAY_SENSITIVITY_TWOFIVESIX_ITEM_ID, L"256x");
			AppendMenu(lightSensitivityMenu_, MF_STRING, TRAY_SENSITIVITY_ONETWOEIGHT_ITEM_ID, L"128x");
			AppendMenu(lightSensitivityMenu_, MF_STRING, TRAY_SENSITIVITY_SIXTYFOUR_ITEM_ID, L"64x");
			AppendMenu(lightSensitivityMenu_, MF_STRING, TRAY_SENSITIVITY_THIRTYTWO_ITEM_ID, L"32x");
			AppendMenu(lightSensitivityMenu_, MF_STRING, TRAY_SENSITIVITY_SIXTEEN_ITEM_ID, L"16x");
			AppendMenu(lightSensitivityMenu_, MF_STRING, TRAY_SENSITIVITY_EIGHT_ITEM_ID, L"8x");
			AppendMenu(lightSensitivityMenu_, MF_STRING, TRAY_SENSITIVITY_FOUR_ITEM_ID, L"4x");
			AppendMenu(lightSensitivityMenu_, MF_STRING, TRAY_SENSITIVITY_TWO_ITEM_ID, L"2x");
			AppendMenu(lightSensitivityMenu_, MF_STRING, TRAY_SENSITIVITY_ONE_ITEM_ID, L"1x");
			AppendMenu(lightSensitivityMenu_, MF_STRING, TRAY_SENSITIVITY_PFIVE_ITEM_ID, L".5x");
			AppendMenu(lightSensitivityMenu_, MF_SEPARATOR, NULL,  NULL);
			AppendMenu(lightSensitivityMenu_, MF_STRING, TRAY_SENSITIVITY_ADAPTIVE_ITEM_ID, L"Δx");
		);


		//
		settingsMenu_ = CreatePopupMenu();
		AppendMenu(settingsMenu_, MF_POPUP, (UINT)modeResponceMenu_,  L"Mode Response");
		REQUIRES_AURORA(AppendMenu(settingsMenu_, MF_POPUP, (UINT)screenSamplingMenu_,  L"Screen Sampling"););
		REQUIRES_SYNESTHESIA(AppendMenu(settingsMenu_, MF_POPUP, (UINT)lightSensitivityMenu_,  L"Sound Sensitivity"););
		AppendMenu(settingsMenu_, MF_SEPARATOR, NULL,  NULL);
		REQUIRES_AURORA(AppendMenu(settingsMenu_, MF_POPUP, (UINT)whiteBalanceMenu_,  L"White Balance"););
		AppendMenu(settingsMenu_, MF_POPUP, (UINT)lightBrightnessMenu_,  L"Light Brightness");
		AppendMenu(settingsMenu_, MF_POPUP, (UINT)lightingArrangementMenu_,  L"Lighting Arrangement");
		


		//
		rootMenu_ = CreatePopupMenu();

		REQUIRES_AURORA(AppendMenu(rootMenu_, MF_POPUP, (UINT)auroraMenu_, L"Aurora Modes"););
		/* else */ REQUIRES_NO_AURORA(AppendMenu(rootMenu_, MF_STRING, TRAY_AURORA_UNAVAILABLE_ITEM_ID,  L"Aurora Unavailable"););

		REQUIRES_SYNESTHESIA(AppendMenu(rootMenu_, MF_POPUP, (UINT)synesthesiaMenu_, L"Synesthesia Modes"););
		/* else */ REQUIRES_NO_SYNESTHESIA(AppendMenu(rootMenu_, MF_STRING, TRAY_SYNESTHESIA_UNAVAILABLE_ITEM_ID,  L"Synesthesia Unavailable"););

		AppendMenu(rootMenu_, MF_SEPARATOR, NULL,  NULL);
		REQUIRES_AURORA(AppendMenu(rootMenu_, MF_POPUP, (UINT)illuminationMenu_,  L"Illumination Presets"););
		REQUIRES_SYNESTHESIA(AppendMenu(rootMenu_, MF_POPUP, (UINT)visualisationMenu_,  L"Visualisation Presets"););
		AppendMenu(rootMenu_, MF_SEPARATOR, NULL,  NULL);
		AppendMenu(rootMenu_, MF_STRING, TRAY_UPDATES_ITEM_ID,  L"Latest Updates");
		AppendMenu(rootMenu_, MF_STRING, TRAY_CONNECT_DISCONNECT_ITEM_ID,  L"Disconnect");
		AppendMenu(rootMenu_, MF_POPUP, (UINT)settingsMenu_, L"Settings");
		AppendMenu(rootMenu_, MF_SEPARATOR, NULL,  NULL);
		AppendMenu(rootMenu_, MF_STRING, TRAY_EXIT_ITEM_ID,  L"Exit");
	);
}

Menu::~Menu(void)
{
	DestroyMenu(rootMenu_);
}

void Menu::respondToClick(POINT cursor, HWND hWnd)
{
	unsigned int click = TrackPopupMenu(rootMenu_,
										TPM_RETURNCMD | TPM_NONOTIFY,
										cursor.x,
										cursor.y,
										0,
										hWnd,
										NULL);

	switch(click)
	{
		case TRAY_AURORA_AVERAGE_ITEM_ID:
			system_->changeScreenMode(AVERAGE_SCREEN);
			break;
		case TRAY_AURORA_VIBRANT_ITEM_ID:
			system_->changeScreenMode(VIBRANT_SCREEN);
			break;
		case TRAY_AURORA_ILLUMINATE_ITEM_ID:
			system_->changeScreenMode(ILLUMINATE_SCREEN);
			break;
		case TRAY_AURORA_DISABLE_ITEM_ID:
			system_->changeScreenMode(DISABLE_SCREEN);
			break;
		case TRAY_AURORA_UNAVAILABLE_ITEM_ID:
			MessageBox(NULL, L"Aurora failed to (re)initialise and is therefore unavailable. Restarting Aurora Synesthesia may resolve this issue.\n", L"Aurora Unavailable", MB_OK | MB_ICONINFORMATION);
			break;


		case TRAY_SYNESTHESIA_AMBIENT_ITEM_ID:
			system_->changeSpectrumMode(AMBIENT_SPECTRUM);
			break;
		case TRAY_SYNESTHESIA_REACTIVE_ITEM_ID:
			system_->changeSpectrumMode(REACTIVE_SPECTRUM);
			break;
		case TRAY_SYNESTHESIA_IMMERSIVE_ITEM_ID:
			system_->changeSpectrumMode(IMMERSIVE_SPECTRUM);
			break;
		case TRAY_SYNESTHESIA_DISABLE_ITEM_ID:
			system_->changeSpectrumMode(DISABLE_SPECTRUM);
			break;
		case TRAY_SYNESTHESIA_UNAVAILABLE_ITEM_ID:
			MessageBox(NULL, L"Synesthesia failed to (re)initialise and is therefore unavailable. Restarting Aurora Synesthesia may resolve this issue.\n", L"Synesthesia Unavailable", MB_OK | MB_ICONINFORMATION);
			break;


		case TRAY_ILLUMINATION_ORIGINAL_ITEM_ID:
			system_->changeIlluminationPreset(ORIGINAL_ILLUMINATION);
			break;
		case TRAY_ILLUMINATION_SPECTRUM_ITEM_ID:
			system_->changeIlluminationPreset(SPECTRUM_ILLUMINATION);
			break;
		case TRAY_ILLUMINATION_CANDLE_ITEM_ID:
			system_->changeIlluminationPreset(CANDLE_ILLUMINATION);
			break;
		case TRAY_ILLUMINATION_RELAX_ITEM_ID:
			system_->changeIlluminationPreset(RELAX_ILLUMINATION);
			break;
		case TRAY_ILLUMINATION_CUSTOM_ITEM_ID:
			system_->changeIlluminationPreset(CUSTOM_ILLUMINATION);
			break;


		case TRAY_VISUALISATION_NATURAL_ITEM_ID:
			system_->changeVisualisationPreset(NATURAL_VISUALISATION);
			break;
		case TRAY_VISUALISATION_LIQUID_ITEM_ID:
			system_->changeVisualisationPreset(LIQUID_VISUALISATION);
			break;
		case TRAY_VISUALISATION_ENERGY_ITEM_ID:
			system_->changeVisualisationPreset(ENERGY_VISUALISATION);
			break;
		case TRAY_VISUALISATION_CUSTOM_ITEM_ID:
			system_->changeVisualisationPreset(CUSTOM_VISUALISATION);
			break;


		case TRAY_MODE_RESPONCE_HIGH_ITEM_ID:
			system_->changeModeResponceSetting(HIGH_RESPONCE);
			break;
		case TRAY_MODE_RESPONCE_STANDARD_ITEM_ID:
			system_->changeModeResponceSetting(STANDARD_RESPONCE);
			break;
		case TRAY_MODE_RESPONCE_LOW_ITEM_ID:
			system_->changeModeResponceSetting(LOW_RESPONCE);
			break;


		case TRAY_SCREEN_SAMPLING_HIGH_ITEM_ID:
			system_->changeScreenSamplingSetting(HIGH_SAMPLING);
			break;
		case TRAY_SCREEN_SAMPLING_STANDARD_ITEM_ID:
			system_->changeScreenSamplingSetting(STANDARD_SAMPLING);
			break;
		case TRAY_SCREEN_SAMPLING_LOW_ITEM_ID:
			system_->changeScreenSamplingSetting(LOW_SAMPLING);
			break;


		case TRAY_WHITE_BALANCE_FIVE_ITEM_ID:
			system_->changeWhiteBalanceSetting(FIVE_WHITE_BALANCE);
			break;
		case TRAY_WHITE_BALANCE_FOUR_ITEM_ID:
			system_->changeWhiteBalanceSetting(FOUR_WHITE_BALANCE);
			break;
		case TRAY_WHITE_BALANCE_THREE_ITEM_ID:
			system_->changeWhiteBalanceSetting(THREE_WHITE_BALANCE);
			break;
		case TRAY_WHITE_BALANCE_TWO_ITEM_ID:
			system_->changeWhiteBalanceSetting(TWO_WHITE_BALANCE);
			break;
		case TRAY_WHITE_BALANCE_ONE_ITEM_ID:
			system_->changeWhiteBalanceSetting(ONE_WHITE_BALANCE);
			break;
		case TRAY_WHITE_BALANCE_OFF_ITEM_ID:
			system_->changeWhiteBalanceSetting(OFF_WHITE_BALANCE);
			break;


		case TRAY_BRIGHTNESS_ONEHUNDRED_ITEM_ID:
			system_->changeLightBrightnessSetting(ONEHUNDRED_BRIGHTNESS);
			break;
		case TRAY_BRIGHTNESS_NINETY_ITEM_ID:
			system_->changeLightBrightnessSetting(NINETY_BRIGHTNESS);
			break;
		case TRAY_BRIGHTNESS_EIGHTY_ITEM_ID:
			system_->changeLightBrightnessSetting(EIGHTY_BRIGHTNESS);
			break;
		case TRAY_BRIGHTNESS_SEVENTY_ITEM_ID:
			system_->changeLightBrightnessSetting(SEVENTY_BRIGHTNESS);
			break;
		case TRAY_BRIGHTNESS_SIXTY_ITEM_ID:
			system_->changeLightBrightnessSetting(SIXTY_BRIGHTNESS);
			break;
		case TRAY_BRIGHTNESS_FIFTY_ITEM_ID:
			system_->changeLightBrightnessSetting(FIFTY_BRIGHTNESS);
			break;
		case TRAY_BRIGHTNESS_FOURTY_ITEM_ID:
			system_->changeLightBrightnessSetting(FOURTY_BRIGHTNESS);
			break;
		case TRAY_BRIGHTNESS_THIRTY_ITEM_ID:
			system_->changeLightBrightnessSetting(THIRTY_BRIGHTNESS);
			break;
		case TRAY_BRIGHTNESS_TWENTY_ITEM_ID:
			system_->changeLightBrightnessSetting(TWENTY_BRIGHTNESS);
			break;
		case TRAY_BRIGHTNESS_TEN_ITEM_ID:
			system_->changeLightBrightnessSetting(TEN_BRIGHTNESS);
			break;


		case TRAY_SENSITIVITY_TWOFIVESIX_ITEM_ID:
			system_->changeLightSensitivitySetting(TWOFIVESIX_SENSITIVITY);
			break;
		case TRAY_SENSITIVITY_ONETWOEIGHT_ITEM_ID:
			system_->changeLightSensitivitySetting(ONETWOEIGHT_SENSITIVITY);
			break;
		case TRAY_SENSITIVITY_SIXTYFOUR_ITEM_ID:
			system_->changeLightSensitivitySetting(SIXTYFOUR_SENSITIVITY);
			break;
		case TRAY_SENSITIVITY_THIRTYTWO_ITEM_ID:
			system_->changeLightSensitivitySetting(THIRTYTWO_SENSITIVITY);
			break;
		case TRAY_SENSITIVITY_SIXTEEN_ITEM_ID:
			system_->changeLightSensitivitySetting(SIXTEEN_SENSITIVITY);
			break;
		case TRAY_SENSITIVITY_EIGHT_ITEM_ID:
			system_->changeLightSensitivitySetting(EIGHT_SENSITIVITY);
			break;
		case TRAY_SENSITIVITY_FOUR_ITEM_ID:
			system_->changeLightSensitivitySetting(FOUR_SENSITIVITY);
			break;
		case TRAY_SENSITIVITY_TWO_ITEM_ID:
			system_->changeLightSensitivitySetting(TWO_SENSITIVITY);
			break;
		case TRAY_SENSITIVITY_ONE_ITEM_ID:
			system_->changeLightSensitivitySetting(ONE_SENSITIVITY);
			break;
		case TRAY_SENSITIVITY_PFIVE_ITEM_ID:
			system_->changeLightSensitivitySetting(PFIVE_SENSITIVITY);
			break;
		case TRAY_SENSITIVITY_ADAPTIVE_ITEM_ID:
			system_->changeLightSensitivitySetting(ADAPTIVE_SENSITIVITY);
			break;


		case TRAY_ARRANGEMENT_STEREO_ITEM_ID:
			system_->changeLightingArrangementSetting(STEREO_ARRANGEMENT);
			break;
		case TRAY_ARRANGEMENT_SURROUND_ITEM_ID:
			system_->changeLightingArrangementSetting(SURROUND_ARRANGEMENT);
			break;

		
		case TRAY_CONNECT_DISCONNECT_ITEM_ID:
			if(system_->currentLightingState() == LIGHTS_ENABLED)
				system_->changeLightingState(LIGHTS_DISABLED);
			else if(system_->currentLightingState() == LIGHTS_DISABLED)
				system_->changeLightingState(LIGHTS_ENABLED);
			break;

		case TRAY_UPDATES_ITEM_ID:
			ShellExecute(hWnd, L"open", L"http://www.ambx.com/forum/viewtopic.php?f=2&t=2766", NULL, NULL, SW_SHOWNORMAL);
			break;

		case TRAY_EXIT_ITEM_ID:
			SendMessage(hWnd, WM_DESTROY, 0, 0);
			break;
	}
}

void Menu::updateOptions(void)
{
	REQUIRES_AURORA(
		switch(system_->currentScreenMode())
		{
			case AVERAGE_SCREEN:
				ModifyMenu(auroraMenu_, TRAY_AURORA_AVERAGE_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_AURORA_AVERAGE_ITEM_ID, L"Average");
				ModifyMenu(auroraMenu_, TRAY_AURORA_VIBRANT_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_AURORA_VIBRANT_ITEM_ID, L"Vibrant");
				ModifyMenu(auroraMenu_, TRAY_AURORA_ILLUMINATE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_AURORA_ILLUMINATE_ITEM_ID, L"Illuminate");
				ModifyMenu(auroraMenu_, TRAY_AURORA_DISABLE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_AURORA_DISABLE_ITEM_ID, L"Disable");
				break;
			case VIBRANT_SCREEN:
				ModifyMenu(auroraMenu_, TRAY_AURORA_AVERAGE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_AURORA_AVERAGE_ITEM_ID, L"Average");
				ModifyMenu(auroraMenu_, TRAY_AURORA_VIBRANT_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_AURORA_VIBRANT_ITEM_ID, L"Vibrant");
				ModifyMenu(auroraMenu_, TRAY_AURORA_ILLUMINATE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_AURORA_ILLUMINATE_ITEM_ID, L"Illuminate");
				ModifyMenu(auroraMenu_, TRAY_AURORA_DISABLE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_AURORA_DISABLE_ITEM_ID, L"Disable");
				break;
			case ILLUMINATE_SCREEN:
				ModifyMenu(auroraMenu_, TRAY_AURORA_AVERAGE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_AURORA_AVERAGE_ITEM_ID, L"Average");
				ModifyMenu(auroraMenu_, TRAY_AURORA_VIBRANT_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_AURORA_VIBRANT_ITEM_ID, L"Vibrant");
				ModifyMenu(auroraMenu_, TRAY_AURORA_ILLUMINATE_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_AURORA_ILLUMINATE_ITEM_ID, L"Illuminate");
				ModifyMenu(auroraMenu_, TRAY_AURORA_DISABLE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_AURORA_DISABLE_ITEM_ID, L"Disable");
				break;
			case DISABLE_SCREEN:
				ModifyMenu(auroraMenu_, TRAY_AURORA_AVERAGE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_AURORA_AVERAGE_ITEM_ID, L"Average");
				ModifyMenu(auroraMenu_, TRAY_AURORA_VIBRANT_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_AURORA_VIBRANT_ITEM_ID, L"Vibrant");
				ModifyMenu(auroraMenu_, TRAY_AURORA_ILLUMINATE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_AURORA_ILLUMINATE_ITEM_ID, L"Illuminate");
				ModifyMenu(auroraMenu_, TRAY_AURORA_DISABLE_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_AURORA_DISABLE_ITEM_ID, L"Disable");
				break;
		}


		switch(system_->currentIlluminationPreset())
		{
			case ORIGINAL_ILLUMINATION:
				ModifyMenu(illuminationMenu_, TRAY_ILLUMINATION_ORIGINAL_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_ILLUMINATION_ORIGINAL_ITEM_ID, L"Original");
				ModifyMenu(illuminationMenu_, TRAY_ILLUMINATION_SPECTRUM_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_ILLUMINATION_SPECTRUM_ITEM_ID, L"Spectrum");
				ModifyMenu(illuminationMenu_, TRAY_ILLUMINATION_CANDLE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_ILLUMINATION_CANDLE_ITEM_ID, L"Candle"); 
				ModifyMenu(illuminationMenu_, TRAY_ILLUMINATION_RELAX_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_ILLUMINATION_RELAX_ITEM_ID, L"Relax"); 
				ModifyMenu(illuminationMenu_, TRAY_ILLUMINATION_CUSTOM_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_ILLUMINATION_CUSTOM_ITEM_ID, L"Custom");
				break;
			case SPECTRUM_ILLUMINATION:
				ModifyMenu(illuminationMenu_, TRAY_ILLUMINATION_ORIGINAL_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_ILLUMINATION_ORIGINAL_ITEM_ID, L"Original");
				ModifyMenu(illuminationMenu_, TRAY_ILLUMINATION_SPECTRUM_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_ILLUMINATION_SPECTRUM_ITEM_ID, L"Spectrum");
				ModifyMenu(illuminationMenu_, TRAY_ILLUMINATION_CANDLE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_ILLUMINATION_CANDLE_ITEM_ID, L"Candle");
				ModifyMenu(illuminationMenu_, TRAY_ILLUMINATION_RELAX_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_ILLUMINATION_RELAX_ITEM_ID, L"Relax");
				ModifyMenu(illuminationMenu_, TRAY_ILLUMINATION_CUSTOM_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_ILLUMINATION_CUSTOM_ITEM_ID, L"Custom");
				break;
			case CANDLE_ILLUMINATION:
				ModifyMenu(illuminationMenu_, TRAY_ILLUMINATION_ORIGINAL_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_ILLUMINATION_ORIGINAL_ITEM_ID, L"Original");
				ModifyMenu(illuminationMenu_, TRAY_ILLUMINATION_SPECTRUM_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_ILLUMINATION_SPECTRUM_ITEM_ID, L"Spectrum");
				ModifyMenu(illuminationMenu_, TRAY_ILLUMINATION_CANDLE_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_ILLUMINATION_CANDLE_ITEM_ID, L"Candle");
				ModifyMenu(illuminationMenu_, TRAY_ILLUMINATION_RELAX_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_ILLUMINATION_RELAX_ITEM_ID, L"Relax"); 
				ModifyMenu(illuminationMenu_, TRAY_ILLUMINATION_CUSTOM_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_ILLUMINATION_CUSTOM_ITEM_ID, L"Custom");
				break;
			case RELAX_ILLUMINATION:
				ModifyMenu(illuminationMenu_, TRAY_ILLUMINATION_ORIGINAL_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_ILLUMINATION_ORIGINAL_ITEM_ID, L"Original");
				ModifyMenu(illuminationMenu_, TRAY_ILLUMINATION_SPECTRUM_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_ILLUMINATION_SPECTRUM_ITEM_ID, L"Spectrum");
				ModifyMenu(illuminationMenu_, TRAY_ILLUMINATION_CANDLE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_ILLUMINATION_CANDLE_ITEM_ID, L"Candle");
				ModifyMenu(illuminationMenu_, TRAY_ILLUMINATION_RELAX_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_ILLUMINATION_RELAX_ITEM_ID, L"Relax"); 
				ModifyMenu(illuminationMenu_, TRAY_ILLUMINATION_CUSTOM_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_ILLUMINATION_CUSTOM_ITEM_ID, L"Custom");
				break;
			case CUSTOM_ILLUMINATION:
				ModifyMenu(illuminationMenu_, TRAY_ILLUMINATION_ORIGINAL_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_ILLUMINATION_ORIGINAL_ITEM_ID, L"Original");
				ModifyMenu(illuminationMenu_, TRAY_ILLUMINATION_SPECTRUM_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_ILLUMINATION_SPECTRUM_ITEM_ID, L"Spectrum");
				ModifyMenu(illuminationMenu_, TRAY_ILLUMINATION_CANDLE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_ILLUMINATION_CANDLE_ITEM_ID, L"Candle");
				ModifyMenu(illuminationMenu_, TRAY_ILLUMINATION_RELAX_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_ILLUMINATION_RELAX_ITEM_ID, L"Relax"); 
				ModifyMenu(illuminationMenu_, TRAY_ILLUMINATION_CUSTOM_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_ILLUMINATION_CUSTOM_ITEM_ID, L"Custom");
				break;
		}


		switch(system_->currentScreenSamplingSetting())
		{
			case HIGH_SAMPLING:
				ModifyMenu(screenSamplingMenu_, TRAY_SCREEN_SAMPLING_HIGH_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_SCREEN_SAMPLING_HIGH_ITEM_ID, L"High"); 
				ModifyMenu(screenSamplingMenu_, TRAY_SCREEN_SAMPLING_STANDARD_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SCREEN_SAMPLING_STANDARD_ITEM_ID, L"Standard"); 
				ModifyMenu(screenSamplingMenu_, TRAY_SCREEN_SAMPLING_LOW_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SCREEN_SAMPLING_LOW_ITEM_ID, L"Low"); 
				break;
			case STANDARD_SAMPLING:
				ModifyMenu(screenSamplingMenu_, TRAY_SCREEN_SAMPLING_HIGH_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SCREEN_SAMPLING_HIGH_ITEM_ID, L"High"); 
				ModifyMenu(screenSamplingMenu_, TRAY_SCREEN_SAMPLING_STANDARD_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_SCREEN_SAMPLING_STANDARD_ITEM_ID, L"Standard"); 
				ModifyMenu(screenSamplingMenu_, TRAY_SCREEN_SAMPLING_LOW_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SCREEN_SAMPLING_LOW_ITEM_ID, L"Low"); 
				break;
			case LOW_SAMPLING:
				ModifyMenu(screenSamplingMenu_, TRAY_SCREEN_SAMPLING_HIGH_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SCREEN_SAMPLING_HIGH_ITEM_ID, L"High"); 
				ModifyMenu(screenSamplingMenu_, TRAY_SCREEN_SAMPLING_STANDARD_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SCREEN_SAMPLING_STANDARD_ITEM_ID, L"Standard"); 
				ModifyMenu(screenSamplingMenu_, TRAY_SCREEN_SAMPLING_LOW_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_SCREEN_SAMPLING_LOW_ITEM_ID, L"Low"); 
				break;
		}


		switch(system_->currentWhiteBalanceSetting())
		{
			case FIVE_WHITE_BALANCE:
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_FIVE_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_WHITE_BALANCE_FIVE_ITEM_ID, L"5"); 
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_FOUR_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_WHITE_BALANCE_FOUR_ITEM_ID, L"4");
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_THREE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_WHITE_BALANCE_THREE_ITEM_ID, L"3");
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_TWO_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_WHITE_BALANCE_TWO_ITEM_ID, L"2");
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_ONE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_WHITE_BALANCE_ONE_ITEM_ID, L"1");
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_OFF_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_WHITE_BALANCE_OFF_ITEM_ID, L"0");
				break;
			case FOUR_WHITE_BALANCE:
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_FIVE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_WHITE_BALANCE_FIVE_ITEM_ID, L"5"); 
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_FOUR_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_WHITE_BALANCE_FOUR_ITEM_ID, L"4");
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_THREE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_WHITE_BALANCE_THREE_ITEM_ID, L"3");
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_TWO_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_WHITE_BALANCE_TWO_ITEM_ID, L"2");
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_ONE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_WHITE_BALANCE_ONE_ITEM_ID, L"1");
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_OFF_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_WHITE_BALANCE_OFF_ITEM_ID, L"0");
				break;
			case THREE_WHITE_BALANCE:
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_FIVE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_WHITE_BALANCE_FIVE_ITEM_ID, L"5"); 
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_FOUR_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_WHITE_BALANCE_FOUR_ITEM_ID, L"4");
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_THREE_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_WHITE_BALANCE_THREE_ITEM_ID, L"3");
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_TWO_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_WHITE_BALANCE_TWO_ITEM_ID, L"2");
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_ONE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_WHITE_BALANCE_ONE_ITEM_ID, L"1");
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_OFF_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_WHITE_BALANCE_OFF_ITEM_ID, L"0");
				break;
			case TWO_WHITE_BALANCE:
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_FIVE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_WHITE_BALANCE_FIVE_ITEM_ID, L"5"); 
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_FOUR_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_WHITE_BALANCE_FOUR_ITEM_ID, L"4");
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_THREE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_WHITE_BALANCE_THREE_ITEM_ID, L"3");
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_TWO_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_WHITE_BALANCE_TWO_ITEM_ID, L"2");
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_ONE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_WHITE_BALANCE_ONE_ITEM_ID, L"1");
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_OFF_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_WHITE_BALANCE_OFF_ITEM_ID, L"0");
				break;
			case ONE_WHITE_BALANCE:
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_FIVE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_WHITE_BALANCE_FIVE_ITEM_ID, L"5"); 
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_FOUR_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_WHITE_BALANCE_FOUR_ITEM_ID, L"4");
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_THREE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_WHITE_BALANCE_THREE_ITEM_ID, L"3");
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_TWO_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_WHITE_BALANCE_TWO_ITEM_ID, L"2");
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_ONE_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_WHITE_BALANCE_ONE_ITEM_ID, L"1");
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_OFF_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_WHITE_BALANCE_OFF_ITEM_ID, L"0");
				break;
			case OFF_WHITE_BALANCE:
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_FIVE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_WHITE_BALANCE_FIVE_ITEM_ID, L"5"); 
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_FOUR_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_WHITE_BALANCE_FOUR_ITEM_ID, L"4");
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_THREE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_WHITE_BALANCE_THREE_ITEM_ID, L"3");
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_TWO_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_WHITE_BALANCE_TWO_ITEM_ID, L"2");
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_ONE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_WHITE_BALANCE_ONE_ITEM_ID, L"1");
				ModifyMenu(whiteBalanceMenu_, TRAY_WHITE_BALANCE_OFF_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_WHITE_BALANCE_OFF_ITEM_ID, L"0");
				break;
		}
	);

	REQUIRES_SYNESTHESIA(
		switch(system_->currentSpectrumMode())
		{
			case AMBIENT_SPECTRUM:
				ModifyMenu(synesthesiaMenu_, TRAY_SYNESTHESIA_AMBIENT_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_SYNESTHESIA_AMBIENT_ITEM_ID, L"Ambient"); 
				ModifyMenu(synesthesiaMenu_, TRAY_SYNESTHESIA_REACTIVE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SYNESTHESIA_REACTIVE_ITEM_ID, L"Reactive");
				ModifyMenu(synesthesiaMenu_, TRAY_SYNESTHESIA_IMMERSIVE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SYNESTHESIA_IMMERSIVE_ITEM_ID, L"Immersive");
				ModifyMenu(synesthesiaMenu_, TRAY_SYNESTHESIA_DISABLE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SYNESTHESIA_DISABLE_ITEM_ID, L"Disable");
				break;
			case REACTIVE_SPECTRUM:
				ModifyMenu(synesthesiaMenu_, TRAY_SYNESTHESIA_AMBIENT_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SYNESTHESIA_AMBIENT_ITEM_ID, L"Ambient"); 
				ModifyMenu(synesthesiaMenu_, TRAY_SYNESTHESIA_REACTIVE_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_SYNESTHESIA_REACTIVE_ITEM_ID, L"Reactive");
				ModifyMenu(synesthesiaMenu_, TRAY_SYNESTHESIA_IMMERSIVE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SYNESTHESIA_IMMERSIVE_ITEM_ID, L"Immersive");
				ModifyMenu(synesthesiaMenu_, TRAY_SYNESTHESIA_DISABLE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SYNESTHESIA_DISABLE_ITEM_ID, L"Disable");
				break;
			case IMMERSIVE_SPECTRUM:
				ModifyMenu(synesthesiaMenu_, TRAY_SYNESTHESIA_AMBIENT_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SYNESTHESIA_AMBIENT_ITEM_ID, L"Ambient"); 
				ModifyMenu(synesthesiaMenu_, TRAY_SYNESTHESIA_REACTIVE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SYNESTHESIA_REACTIVE_ITEM_ID, L"Reactive");
				ModifyMenu(synesthesiaMenu_, TRAY_SYNESTHESIA_IMMERSIVE_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_SYNESTHESIA_IMMERSIVE_ITEM_ID, L"Immersive");
				ModifyMenu(synesthesiaMenu_, TRAY_SYNESTHESIA_DISABLE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SYNESTHESIA_DISABLE_ITEM_ID, L"Disable");
				break;
			case DISABLE_SPECTRUM:
				ModifyMenu(synesthesiaMenu_, TRAY_SYNESTHESIA_AMBIENT_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SYNESTHESIA_AMBIENT_ITEM_ID, L"Ambient"); 
				ModifyMenu(synesthesiaMenu_, TRAY_SYNESTHESIA_REACTIVE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SYNESTHESIA_REACTIVE_ITEM_ID, L"Reactive");
				ModifyMenu(synesthesiaMenu_, TRAY_SYNESTHESIA_IMMERSIVE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SYNESTHESIA_IMMERSIVE_ITEM_ID, L"Immersive");
				ModifyMenu(synesthesiaMenu_, TRAY_SYNESTHESIA_DISABLE_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_SYNESTHESIA_DISABLE_ITEM_ID, L"Disable");
				break;
		}
	

		switch(system_->currentVisualisationPreset())
		{
			case NATURAL_VISUALISATION:
				ModifyMenu(visualisationMenu_, TRAY_VISUALISATION_NATURAL_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_VISUALISATION_NATURAL_ITEM_ID, L"Natural"); 
				ModifyMenu(visualisationMenu_, TRAY_VISUALISATION_LIQUID_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_VISUALISATION_LIQUID_ITEM_ID, L"Liquid"); 
				ModifyMenu(visualisationMenu_, TRAY_VISUALISATION_ENERGY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_VISUALISATION_ENERGY_ITEM_ID, L"Energy");
				ModifyMenu(visualisationMenu_, TRAY_VISUALISATION_CUSTOM_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_VISUALISATION_CUSTOM_ITEM_ID, L"Custom");
				break;
			case LIQUID_VISUALISATION:
				ModifyMenu(visualisationMenu_, TRAY_VISUALISATION_NATURAL_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_VISUALISATION_NATURAL_ITEM_ID, L"Natural"); 
				ModifyMenu(visualisationMenu_, TRAY_VISUALISATION_LIQUID_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_VISUALISATION_LIQUID_ITEM_ID, L"Liquid"); 
				ModifyMenu(visualisationMenu_, TRAY_VISUALISATION_ENERGY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_VISUALISATION_ENERGY_ITEM_ID, L"Energy");
				ModifyMenu(visualisationMenu_, TRAY_VISUALISATION_CUSTOM_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_VISUALISATION_CUSTOM_ITEM_ID, L"Custom");
				break;
			case ENERGY_VISUALISATION:
				ModifyMenu(visualisationMenu_, TRAY_VISUALISATION_NATURAL_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_VISUALISATION_NATURAL_ITEM_ID, L"Natural"); 
				ModifyMenu(visualisationMenu_, TRAY_VISUALISATION_LIQUID_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_VISUALISATION_LIQUID_ITEM_ID, L"Liquid"); 
				ModifyMenu(visualisationMenu_, TRAY_VISUALISATION_ENERGY_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_VISUALISATION_ENERGY_ITEM_ID, L"Energy");
				ModifyMenu(visualisationMenu_, TRAY_VISUALISATION_CUSTOM_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_VISUALISATION_CUSTOM_ITEM_ID, L"Custom");
				break;
			case CUSTOM_VISUALISATION:
				ModifyMenu(visualisationMenu_, TRAY_VISUALISATION_NATURAL_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_VISUALISATION_NATURAL_ITEM_ID, L"Natural"); 
				ModifyMenu(visualisationMenu_, TRAY_VISUALISATION_LIQUID_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_VISUALISATION_LIQUID_ITEM_ID, L"Liquid"); 
				ModifyMenu(visualisationMenu_, TRAY_VISUALISATION_ENERGY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_VISUALISATION_ENERGY_ITEM_ID, L"Energy");
				ModifyMenu(visualisationMenu_, TRAY_VISUALISATION_CUSTOM_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_VISUALISATION_CUSTOM_ITEM_ID, L"Custom");
				break;
		}
		

		switch(system_->currentLightSensitivitySetting())
		{
			case TWOFIVESIX_SENSITIVITY:
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_TWOFIVESIX_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_SENSITIVITY_TWOFIVESIX_ITEM_ID, L"256x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_ONETWOEIGHT_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_ONETWOEIGHT_ITEM_ID, L"128x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_SIXTYFOUR_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_SIXTYFOUR_ITEM_ID, L"64x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_THIRTYTWO_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_THIRTYTWO_ITEM_ID, L"32x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_SIXTEEN_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_SIXTEEN_ITEM_ID, L"16x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_EIGHT_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_EIGHT_ITEM_ID, L"8x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_FOUR_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_FOUR_ITEM_ID, L"4x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_TWO_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_TWO_ITEM_ID, L"2x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_ONE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_ONE_ITEM_ID, L"1x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_PFIVE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_PFIVE_ITEM_ID, L".5x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_ADAPTIVE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_ADAPTIVE_ITEM_ID, L"Δx"); 
				break;
			case ONETWOEIGHT_SENSITIVITY:
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_TWOFIVESIX_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_TWOFIVESIX_ITEM_ID, L"256x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_ONETWOEIGHT_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_SENSITIVITY_ONETWOEIGHT_ITEM_ID, L"128x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_SIXTYFOUR_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_SIXTYFOUR_ITEM_ID, L"64x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_THIRTYTWO_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_THIRTYTWO_ITEM_ID, L"32x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_SIXTEEN_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_SIXTEEN_ITEM_ID, L"16x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_EIGHT_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_EIGHT_ITEM_ID, L"8x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_FOUR_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_FOUR_ITEM_ID, L"4x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_TWO_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_TWO_ITEM_ID, L"2x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_ONE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_ONE_ITEM_ID, L"1x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_PFIVE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_PFIVE_ITEM_ID, L".5x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_ADAPTIVE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_ADAPTIVE_ITEM_ID, L"Δx"); 
				break;
			case SIXTYFOUR_SENSITIVITY:
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_TWOFIVESIX_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_TWOFIVESIX_ITEM_ID, L"256x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_ONETWOEIGHT_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_ONETWOEIGHT_ITEM_ID, L"128x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_SIXTYFOUR_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_SENSITIVITY_SIXTYFOUR_ITEM_ID, L"64x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_THIRTYTWO_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_THIRTYTWO_ITEM_ID, L"32x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_SIXTEEN_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_SIXTEEN_ITEM_ID, L"16x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_EIGHT_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_EIGHT_ITEM_ID, L"8x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_FOUR_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_FOUR_ITEM_ID, L"4x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_TWO_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_TWO_ITEM_ID, L"2x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_ONE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_ONE_ITEM_ID, L"1x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_PFIVE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_PFIVE_ITEM_ID, L".5x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_ADAPTIVE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_ADAPTIVE_ITEM_ID, L"Δx"); 
				break;
			case THIRTYTWO_SENSITIVITY:
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_TWOFIVESIX_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_TWOFIVESIX_ITEM_ID, L"256x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_ONETWOEIGHT_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_ONETWOEIGHT_ITEM_ID, L"128x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_SIXTYFOUR_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_SIXTYFOUR_ITEM_ID, L"64x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_THIRTYTWO_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_SENSITIVITY_THIRTYTWO_ITEM_ID, L"32x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_SIXTEEN_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_SIXTEEN_ITEM_ID, L"16x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_EIGHT_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_EIGHT_ITEM_ID, L"8x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_FOUR_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_FOUR_ITEM_ID, L"4x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_TWO_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_TWO_ITEM_ID, L"2x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_ONE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_ONE_ITEM_ID, L"1x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_PFIVE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_PFIVE_ITEM_ID, L".5x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_ADAPTIVE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_ADAPTIVE_ITEM_ID, L"Δx"); 
				break;
			case SIXTEEN_SENSITIVITY:
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_TWOFIVESIX_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_TWOFIVESIX_ITEM_ID, L"256x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_ONETWOEIGHT_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_ONETWOEIGHT_ITEM_ID, L"128x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_SIXTYFOUR_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_SIXTYFOUR_ITEM_ID, L"64x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_THIRTYTWO_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_THIRTYTWO_ITEM_ID, L"32x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_SIXTEEN_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_SENSITIVITY_SIXTEEN_ITEM_ID, L"16x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_EIGHT_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_EIGHT_ITEM_ID, L"8x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_FOUR_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_FOUR_ITEM_ID, L"4x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_TWO_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_TWO_ITEM_ID, L"2x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_ONE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_ONE_ITEM_ID, L"1x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_PFIVE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_PFIVE_ITEM_ID, L".5x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_ADAPTIVE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_ADAPTIVE_ITEM_ID, L"Δx"); 
				break;
			case EIGHT_SENSITIVITY:
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_TWOFIVESIX_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_TWOFIVESIX_ITEM_ID, L"256x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_ONETWOEIGHT_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_ONETWOEIGHT_ITEM_ID, L"128x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_SIXTYFOUR_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_SIXTYFOUR_ITEM_ID, L"64x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_THIRTYTWO_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_THIRTYTWO_ITEM_ID, L"32x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_SIXTEEN_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_SIXTEEN_ITEM_ID, L"16x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_EIGHT_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_SENSITIVITY_EIGHT_ITEM_ID, L"8x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_FOUR_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_FOUR_ITEM_ID, L"4x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_TWO_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_TWO_ITEM_ID, L"2x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_ONE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_ONE_ITEM_ID, L"1x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_PFIVE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_PFIVE_ITEM_ID, L".5x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_ADAPTIVE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_ADAPTIVE_ITEM_ID, L"Δx"); 
				break;
			case FOUR_SENSITIVITY:
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_TWOFIVESIX_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_TWOFIVESIX_ITEM_ID, L"256x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_ONETWOEIGHT_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_ONETWOEIGHT_ITEM_ID, L"128x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_SIXTYFOUR_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_SIXTYFOUR_ITEM_ID, L"64x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_THIRTYTWO_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_THIRTYTWO_ITEM_ID, L"32x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_SIXTEEN_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_SIXTEEN_ITEM_ID, L"16x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_EIGHT_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_EIGHT_ITEM_ID, L"8x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_FOUR_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_SENSITIVITY_FOUR_ITEM_ID, L"4x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_TWO_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_TWO_ITEM_ID, L"2x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_ONE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_ONE_ITEM_ID, L"1x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_PFIVE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_PFIVE_ITEM_ID, L".5x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_ADAPTIVE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_ADAPTIVE_ITEM_ID, L"Δx"); 
				break;
			case TWO_SENSITIVITY:
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_TWOFIVESIX_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_TWOFIVESIX_ITEM_ID, L"256x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_ONETWOEIGHT_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_ONETWOEIGHT_ITEM_ID, L"128x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_SIXTYFOUR_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_SIXTYFOUR_ITEM_ID, L"64x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_THIRTYTWO_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_THIRTYTWO_ITEM_ID, L"32x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_SIXTEEN_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_SIXTEEN_ITEM_ID, L"16x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_EIGHT_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_EIGHT_ITEM_ID, L"8x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_FOUR_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_FOUR_ITEM_ID, L"4x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_TWO_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_SENSITIVITY_TWO_ITEM_ID, L"2x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_ONE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_ONE_ITEM_ID, L"1x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_PFIVE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_PFIVE_ITEM_ID, L".5x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_ADAPTIVE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_ADAPTIVE_ITEM_ID, L"Δx"); 
				break;
			case ONE_SENSITIVITY:
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_TWOFIVESIX_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_TWOFIVESIX_ITEM_ID, L"256x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_ONETWOEIGHT_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_ONETWOEIGHT_ITEM_ID, L"128x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_SIXTYFOUR_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_SIXTYFOUR_ITEM_ID, L"64x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_THIRTYTWO_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_THIRTYTWO_ITEM_ID, L"32x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_SIXTEEN_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_SIXTEEN_ITEM_ID, L"16x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_EIGHT_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_EIGHT_ITEM_ID, L"8x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_FOUR_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_FOUR_ITEM_ID, L"4x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_TWO_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_TWO_ITEM_ID, L"2x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_ONE_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_SENSITIVITY_ONE_ITEM_ID, L"1x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_PFIVE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_PFIVE_ITEM_ID, L".5x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_ADAPTIVE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_ADAPTIVE_ITEM_ID, L"Δx"); 
				break;
			case PFIVE_SENSITIVITY:
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_TWOFIVESIX_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_TWOFIVESIX_ITEM_ID, L"256x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_ONETWOEIGHT_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_ONETWOEIGHT_ITEM_ID, L"128x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_SIXTYFOUR_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_SIXTYFOUR_ITEM_ID, L"64x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_THIRTYTWO_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_THIRTYTWO_ITEM_ID, L"32x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_SIXTEEN_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_SIXTEEN_ITEM_ID, L"16x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_EIGHT_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_EIGHT_ITEM_ID, L"8x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_FOUR_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_FOUR_ITEM_ID, L"4x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_TWO_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_TWO_ITEM_ID, L"2x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_ONE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_ONE_ITEM_ID, L"1x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_PFIVE_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_SENSITIVITY_PFIVE_ITEM_ID, L".5x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_ADAPTIVE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_ADAPTIVE_ITEM_ID, L"Δx"); 
				break;
			case ADAPTIVE_SENSITIVITY:
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_TWOFIVESIX_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_TWOFIVESIX_ITEM_ID, L"256x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_ONETWOEIGHT_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_ONETWOEIGHT_ITEM_ID, L"128x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_SIXTYFOUR_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_SIXTYFOUR_ITEM_ID, L"64x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_THIRTYTWO_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_THIRTYTWO_ITEM_ID, L"32x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_SIXTEEN_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_SIXTEEN_ITEM_ID, L"16x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_EIGHT_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_EIGHT_ITEM_ID, L"8x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_FOUR_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_FOUR_ITEM_ID, L"4x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_TWO_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_TWO_ITEM_ID, L"2x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_ONE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_ONE_ITEM_ID, L"1x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_PFIVE_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_SENSITIVITY_PFIVE_ITEM_ID, L".5x");
				ModifyMenu(lightSensitivityMenu_, TRAY_SENSITIVITY_ADAPTIVE_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_SENSITIVITY_ADAPTIVE_ITEM_ID, L"Δx"); 
				break;
		}
	);


	REQUIRES_EITHER(
		switch(system_->currentModeResponceSetting())
		{
			case HIGH_RESPONCE:
				ModifyMenu(modeResponceMenu_, TRAY_MODE_RESPONCE_HIGH_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_MODE_RESPONCE_HIGH_ITEM_ID, L"High"); 
				ModifyMenu(modeResponceMenu_, TRAY_MODE_RESPONCE_STANDARD_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_MODE_RESPONCE_STANDARD_ITEM_ID, L"Standard"); 
				ModifyMenu(modeResponceMenu_, TRAY_MODE_RESPONCE_LOW_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_MODE_RESPONCE_LOW_ITEM_ID, L"Low");
				break;
			case STANDARD_RESPONCE:
				ModifyMenu(modeResponceMenu_, TRAY_MODE_RESPONCE_HIGH_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_MODE_RESPONCE_HIGH_ITEM_ID, L"High"); 
				ModifyMenu(modeResponceMenu_, TRAY_MODE_RESPONCE_STANDARD_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_MODE_RESPONCE_STANDARD_ITEM_ID, L"Standard"); 
				ModifyMenu(modeResponceMenu_, TRAY_MODE_RESPONCE_LOW_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_MODE_RESPONCE_LOW_ITEM_ID, L"Low");
				break;
			case LOW_RESPONCE:
				ModifyMenu(modeResponceMenu_, TRAY_MODE_RESPONCE_HIGH_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_MODE_RESPONCE_HIGH_ITEM_ID, L"High"); 
				ModifyMenu(modeResponceMenu_, TRAY_MODE_RESPONCE_STANDARD_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_MODE_RESPONCE_STANDARD_ITEM_ID, L"Standard"); 
				ModifyMenu(modeResponceMenu_, TRAY_MODE_RESPONCE_LOW_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_MODE_RESPONCE_LOW_ITEM_ID, L"Low");
				break;
		}


		switch(system_->currentLightBrightnessSetting())
		{
			case ONEHUNDRED_BRIGHTNESS:
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_ONEHUNDRED_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_BRIGHTNESS_ONEHUNDRED_ITEM_ID, L"100%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_NINETY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_NINETY_ITEM_ID, L"90%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_EIGHTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_EIGHTY_ITEM_ID, L"80%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_SEVENTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_SEVENTY_ITEM_ID, L"70%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_SIXTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_SIXTY_ITEM_ID, L"60%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_FIFTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_FIFTY_ITEM_ID, L"50%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_FOURTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_FOURTY_ITEM_ID, L"40%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_THIRTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_THIRTY_ITEM_ID, L"30%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_TWENTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_TWENTY_ITEM_ID, L"20%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_TEN_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_TEN_ITEM_ID, L"10%");
				break;
			case NINETY_BRIGHTNESS:
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_ONEHUNDRED_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_ONEHUNDRED_ITEM_ID, L"100%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_NINETY_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_BRIGHTNESS_NINETY_ITEM_ID, L"90%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_EIGHTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_EIGHTY_ITEM_ID, L"80%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_SEVENTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_SEVENTY_ITEM_ID, L"70%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_SIXTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_SIXTY_ITEM_ID, L"60%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_FIFTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_FIFTY_ITEM_ID, L"50%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_FOURTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_FOURTY_ITEM_ID, L"40%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_THIRTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_THIRTY_ITEM_ID, L"30%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_TWENTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_TWENTY_ITEM_ID, L"20%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_TEN_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_TEN_ITEM_ID, L"10%");
				break;
			case EIGHTY_BRIGHTNESS:
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_ONEHUNDRED_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_ONEHUNDRED_ITEM_ID, L"100%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_NINETY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_NINETY_ITEM_ID, L"90%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_EIGHTY_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_BRIGHTNESS_EIGHTY_ITEM_ID, L"80%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_SEVENTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_SEVENTY_ITEM_ID, L"70%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_SIXTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_SIXTY_ITEM_ID, L"60%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_FIFTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_FIFTY_ITEM_ID, L"50%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_FOURTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_FOURTY_ITEM_ID, L"40%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_THIRTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_THIRTY_ITEM_ID, L"30%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_TWENTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_TWENTY_ITEM_ID, L"20%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_TEN_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_TEN_ITEM_ID, L"10%");
				break;
			case SEVENTY_BRIGHTNESS:
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_ONEHUNDRED_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_ONEHUNDRED_ITEM_ID, L"100%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_NINETY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_NINETY_ITEM_ID, L"90%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_EIGHTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_EIGHTY_ITEM_ID, L"80%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_SEVENTY_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_BRIGHTNESS_SEVENTY_ITEM_ID, L"70%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_SIXTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_SIXTY_ITEM_ID, L"60%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_FIFTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_FIFTY_ITEM_ID, L"50%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_FOURTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_FOURTY_ITEM_ID, L"40%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_THIRTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_THIRTY_ITEM_ID, L"30%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_TWENTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_TWENTY_ITEM_ID, L"20%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_TEN_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_TEN_ITEM_ID, L"10%");
				break;
			case SIXTY_BRIGHTNESS:
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_ONEHUNDRED_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_ONEHUNDRED_ITEM_ID, L"100%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_NINETY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_NINETY_ITEM_ID, L"90%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_EIGHTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_EIGHTY_ITEM_ID, L"80%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_SEVENTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_SEVENTY_ITEM_ID, L"70%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_SIXTY_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_BRIGHTNESS_SIXTY_ITEM_ID, L"60%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_FIFTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_FIFTY_ITEM_ID, L"50%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_FOURTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_FOURTY_ITEM_ID, L"40%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_THIRTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_THIRTY_ITEM_ID, L"30%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_TWENTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_TWENTY_ITEM_ID, L"20%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_TEN_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_TEN_ITEM_ID, L"10%");
				break;
			case FIFTY_BRIGHTNESS:
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_ONEHUNDRED_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_ONEHUNDRED_ITEM_ID, L"100%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_NINETY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_NINETY_ITEM_ID, L"90%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_EIGHTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_EIGHTY_ITEM_ID, L"80%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_SEVENTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_SEVENTY_ITEM_ID, L"70%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_SIXTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_SIXTY_ITEM_ID, L"60%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_FIFTY_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_BRIGHTNESS_FIFTY_ITEM_ID, L"50%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_FOURTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_FOURTY_ITEM_ID, L"40%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_THIRTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_THIRTY_ITEM_ID, L"30%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_TWENTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_TWENTY_ITEM_ID, L"20%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_TEN_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_TEN_ITEM_ID, L"10%");
				break;
			case FOURTY_BRIGHTNESS:
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_ONEHUNDRED_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_ONEHUNDRED_ITEM_ID, L"100%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_NINETY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_NINETY_ITEM_ID, L"90%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_EIGHTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_EIGHTY_ITEM_ID, L"80%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_SEVENTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_SEVENTY_ITEM_ID, L"70%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_SIXTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_SIXTY_ITEM_ID, L"60%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_FIFTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_FIFTY_ITEM_ID, L"50%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_FOURTY_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_BRIGHTNESS_FOURTY_ITEM_ID, L"40%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_THIRTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_THIRTY_ITEM_ID, L"30%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_TWENTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_TWENTY_ITEM_ID, L"20%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_TEN_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_TEN_ITEM_ID, L"10%");
				break;
			case THIRTY_BRIGHTNESS:
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_ONEHUNDRED_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_ONEHUNDRED_ITEM_ID, L"100%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_NINETY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_NINETY_ITEM_ID, L"90%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_EIGHTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_EIGHTY_ITEM_ID, L"80%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_SEVENTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_SEVENTY_ITEM_ID, L"70%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_SIXTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_SIXTY_ITEM_ID, L"60%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_FIFTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_FIFTY_ITEM_ID, L"50%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_FOURTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_FOURTY_ITEM_ID, L"40%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_THIRTY_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_BRIGHTNESS_THIRTY_ITEM_ID, L"30%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_TWENTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_TWENTY_ITEM_ID, L"20%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_TEN_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_TEN_ITEM_ID, L"10%");
				break;
			case TWENTY_BRIGHTNESS:
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_ONEHUNDRED_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_ONEHUNDRED_ITEM_ID, L"100%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_NINETY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_NINETY_ITEM_ID, L"90%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_EIGHTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_EIGHTY_ITEM_ID, L"80%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_SEVENTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_SEVENTY_ITEM_ID, L"70%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_SIXTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_SIXTY_ITEM_ID, L"60%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_FIFTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_FIFTY_ITEM_ID, L"50%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_FOURTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_FOURTY_ITEM_ID, L"40%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_THIRTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_THIRTY_ITEM_ID, L"30%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_TWENTY_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_BRIGHTNESS_TWENTY_ITEM_ID, L"20%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_TEN_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_TEN_ITEM_ID, L"10%");
				break;
			case TEN_BRIGHTNESS:
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_ONEHUNDRED_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_ONEHUNDRED_ITEM_ID, L"100%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_NINETY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_NINETY_ITEM_ID, L"90%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_EIGHTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_EIGHTY_ITEM_ID, L"80%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_SEVENTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_SEVENTY_ITEM_ID, L"70%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_SIXTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_SIXTY_ITEM_ID, L"60%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_FIFTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_FIFTY_ITEM_ID, L"50%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_FOURTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_FOURTY_ITEM_ID, L"40%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_THIRTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_THIRTY_ITEM_ID, L"30%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_TWENTY_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_BRIGHTNESS_TWENTY_ITEM_ID, L"20%");
				ModifyMenu(lightBrightnessMenu_, TRAY_BRIGHTNESS_TEN_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_BRIGHTNESS_TEN_ITEM_ID, L"10%");
				break;
		}


		switch(system_->currentLightingArrangementSetting())
		{
			case STEREO_ARRANGEMENT:
				ModifyMenu(lightingArrangementMenu_, TRAY_ARRANGEMENT_STEREO_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_ARRANGEMENT_STEREO_ITEM_ID, L"Stereo"); 
				ModifyMenu(lightingArrangementMenu_, TRAY_ARRANGEMENT_SURROUND_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_ARRANGEMENT_SURROUND_ITEM_ID, L"Surround");
				break;
			case SURROUND_ARRANGEMENT:
				ModifyMenu(lightingArrangementMenu_, TRAY_ARRANGEMENT_STEREO_ITEM_ID, MF_BYCOMMAND | MF_ENABLED, TRAY_ARRANGEMENT_STEREO_ITEM_ID, L"Stereo"); 
				ModifyMenu(lightingArrangementMenu_, TRAY_ARRANGEMENT_SURROUND_ITEM_ID, MF_BYCOMMAND | MF_GRAYED, TRAY_ARRANGEMENT_SURROUND_ITEM_ID, L"Surround");
				break;
		}


		switch(system_->currentLightingState())
		{
			case LIGHTS_DISABLED:
				ModifyMenu(rootMenu_, TRAY_CONNECT_DISCONNECT_ITEM_ID, MF_BYCOMMAND, TRAY_CONNECT_DISCONNECT_ITEM_ID, L"Reconnect"); 
				break;
			case LIGHTS_ENABLED:
				ModifyMenu(rootMenu_, TRAY_CONNECT_DISCONNECT_ITEM_ID, MF_BYCOMMAND, TRAY_CONNECT_DISCONNECT_ITEM_ID, L"Disconnect"); 
				break;
		}
	);
}