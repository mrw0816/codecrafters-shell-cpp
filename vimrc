
set t_u7=

set noerrorbells
set visualbell
set autoindent
set expandtab
set shiftround
set shiftwidth=4
set smarttab
set tabstop=4
set hlsearch
set ignorecase
set smartcase
syntax enable
set wrap
set ruler
set wildmenu
set cursorline
set number
set background=dark
set dir=~/.cache/vim

inoremap jj <Esc>
nnoremap <Space>h <C-w>h
nnoremap <Space>j <C-w>j
nnoremap <Space>k <C-w>k
nnoremap <Space>l <C-w>l
nnoremap <S-k> gt
nnoremap <S-j> gT


autocmd VimEnter * NERDTree
autocmd TabNew * NERDTree | wincmd p
autocmd FileType nerdtree nnoremap <buffer> <S-j> gt
autocmd FileType nerdtree nnoremap <buffer> <S-k> gT
let g:NERDTreeMapJumpNextSibling = ''
let g:NERDTreeMapJumpPrevSibling = ''
autocmd FileType nerdtree nnoremap <buffer> s :execute 'vsplit ' . g:NERDTreeFileNode.GetSelected().path.str()<CR>:wincmd L<CR>

