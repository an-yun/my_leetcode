
" 编译运行
nnoremap <F5> :w<CR> :call CompileRun()<CR>
func! CompileRun()
    if &filetype == 'c'
        exec "!echo 'clang % -o ../build/%< -I../include && ../build/%<' && clang % -o ../build/%< -I../include && ../build/%<" 
    elseif &filetype == 'cpp'
        exec "!echo 'clang++ % -o ../build/%< -I../include && ../build/%< -std=c++17' && clang++ % -o ../build/%< -I../include -std=c++17&& ../build/%<" 
    endif
endfunc

