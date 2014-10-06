" vim setting
set nu
set hlsearch
set incsearch
set autoindent
set ignorecase smartcase
set ruler
set laststatus=2
set tabstop=4
set shiftwidth=4
" set mouse=a
set statusline=%F%m%r%h%w\ [TYPE=%Y]\ [POS=%l,%v][%p%%]\ %{strftime(\"%Y/%m/%d\ -\ %H:%M\")}
syntax on
filetype plugin on
let mapleader=','

" ctags setting
nmap <silent> <leader>n :tnext<cr>
nmap <silent> <leader>m :tprev<cr>

" taglist setting
let Tlist_Show_One_File = 1
let Tlist_Exit_OnlyWindow = 1
nmap <silent> <leader>t :TlistToggle<cr>
let g:C_UseTool_cmake    = 'yes'
let g:C_UseTool_doxygen  = 'yes'

