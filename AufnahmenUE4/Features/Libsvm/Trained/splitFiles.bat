@echo off
setlocal enableextensions
index=0
for /f "usebackq delims=|" %%f in ('dir /b "..\"') do (
	if NOT %%f == "FeatureNameLabelMapping.txt" (	
		if %index == 0 (
			copy %%f "Training"
			set /a index=1
		) else (
			copy %%f "Test"
			set /a index=0
		)
	)
)
endlocal


@echo off
setlocal enableextensions
index=0
		if %index == 0 (
			copy %%f "Training"
			set /a index=1
		) else (
			copy %%f "Test"
			set /a index=0
		)
endlocal
