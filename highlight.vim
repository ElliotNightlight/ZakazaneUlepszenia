
autocmd Syntax * syntax keyword ZIntTypes Int8 Int16 Int32 Int64 IntSize
autocmd Syntax * syntax keyword ZUIntTypes UInt8 UInt16 UInt32 UInt64 UIntSize
autocmd Syntax * syntax keyword ZFloatTypes Float32 Float64 FloatExt
highlight link ZIntTypes Type
highlight link ZUIntTypes Type
highlight link ZFloatTypes Type

autocmd Syntax * syntax keyword ZIntLimits Int8_MAX Int8_MIN Int16_MAX Int16_MIN Int32_MAX Int32_MIN Int64_MAX Int64_MIN
autocmd Syntax * syntax keyword ZUIntLimits UInt8_MAX UInt16_MAX UInt32_MAX UInt64_MAX
highlight link ZIntLimits Constant
highlight link ZUIntLimits Constant

autocmd Syntax * syntax keyword ZLoops Range RangeReversed
highlight link ZLoops Statement

