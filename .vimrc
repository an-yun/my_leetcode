
" 编译运行
nnoremap <F5> :w<CR> :call CompileRun()<CR>
func! CompileRun()
    if &filetype == 'c'
        let l:run_cmd = "clang % -g -o ./build/%:t:r -I./include && ./build/%:t:r"
    elseif &filetype == 'cpp'
        let l:run_cmd = "clang++ % -g -o ./build/%:t:r -I./include -std=c++17 -stdlib=libc++ && ./build/%:t:r"
    endif
    exec "!echo '" . l:run_cmd . "' && " l:run_cmd
endfunc

