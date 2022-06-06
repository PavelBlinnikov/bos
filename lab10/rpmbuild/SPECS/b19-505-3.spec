Name:          b19-505-3
Version:       1.0
Release:       1%{?dist}
Summary:       Программа студента Блинникова Павла группы Б19-505
Group:         Testing
License:       GPL
URL:           https://github.com/PavelBlinnikov/bos
Source0:       %{name}-%{version}.tar.gz
BuildRequires: /bin/rm, /bin/mkdir, /bin/cp
Requires:      /bin/bash, /usr/bin/date
BuildArch:     noarch

%description
A test package

%prep
%setup -q

%install
mkdir -p %{buildroot}%{_bindir}
install -m 755 b19-505-3 %{buildroot}%{_bindir}

%files
%{_bindir}/b19-505-3

%changelog
* Thu Oct 16 2012 <Блинников>
- Added %{_bindir}/b19-505-3
