//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.04
// ���e�@�F���͏���
//-------------------------------------------------------
#include <Core\input_state.h>
#include <Def\window_def.h>

using namespace Core;

InputState::InputState()
{
	m_direct_input = 0;
	m_keyboard = 0;
	m_mouse = 0;
}

InputState::InputState(const InputState&)
{
}

InputState::~InputState()
{
}

//������
bool InputState::Initialize(HINSTANCE hInstance, HWND hwnd)
{
	HRESULT result;

	m_mouse_x = 0;
	m_mouse_y = 0;

	result = DirectInput8Create(					//Initialize input�i�f�o�C�X�̐����͂��̌�j
								hInstance,
								DIRECTINPUT_VERSION, IID_IDirectInput8,
								(void**)&m_direct_input, NULL);
	if (FAILED(result))
		return false;

	result = m_direct_input->CreateDevice(GUID_SysKeyboard, &m_keyboard, NULL);			//�L�[�{�[�h�f�o�C�X�𐶐�
	if (FAILED(result))
		return false;

	result = m_keyboard->SetDataFormat(&c_dfDIKeyboard);
	if (FAILED(result))
		return false;

	result = m_keyboard->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_EXCLUSIVE);	//EXCLUSIVE(����Window�ɓ��͂̉e�����o�Ȃ�)
	if (FAILED(result))
		return false;

	result = m_keyboard->Acquire();
	if (FAILED(result))
		return false;

	result = m_direct_input->CreateDevice(GUID_SysMouse, &m_mouse, NULL);				//�}�E�X�f�o�C�X�𐶐�
	if (FAILED(result))
		return false;

	result = m_mouse->SetDataFormat(&c_dfDIMouse);
	if (FAILED(result))
		return false;

	result = m_mouse->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);	//NONEXCLUSIVE(Window���o�Ă��邩�m�F�p)
	if (FAILED(result))
		return false;

	result = m_mouse->Acquire();
	if (FAILED(result))
		return false;

	return true;
}

//�V���b�g�_�E������
void InputState::ShutDown()
{
	if (m_mouse)				//�}�E�X�����
	{
		m_mouse->Unacquire();
		m_mouse->Release();
		m_mouse = 0;
	}

	if (m_keyboard)				//�L�[�{�[�h�����
	{
		m_keyboard->Unacquire();
		m_keyboard->Release();
		m_keyboard = 0;
	}

	if (m_direct_input)			//Input�����
	{
		m_direct_input->Release();
		m_direct_input = 0;
	}
}

//�X�V����
bool InputState::Update()
{
	bool result;

	UpdateKeyboard();				//�O�t���[����KeyboardState�X�V
	result = ReadKeyboard();		//���̃t���[����KeyboardState�X�V
	if (!result)
		return false;

	result = ReadMouse();			//MouseState�X�V
	if (!result)
		return false;
	ClampMousePosition();			//Mouse�̈ʒu����ʓ���

	return true;
}

//���̃t���[����KeyState�X�V
bool InputState::ReadKeyboard()
{
	HRESULT result = m_keyboard->GetDeviceState(sizeof(m_current_keyboard_state), (LPVOID)&m_current_keyboard_state);

	if (result == DI_OK)		//Keyboard�擾�ł�����True
	{
		return true;
	}

	//����Window�����C���Ȃǂ̏ꍇ�͎擾�����݂�
	if (result == DIERR_INPUTLOST || result == DIERR_NOTACQUIRED)
	{
		m_keyboard->Acquire();
		return true;
	}

	return false;				//���̑��̏ꍇ
}

//���̃t���[����MouseState�X�V
bool InputState::ReadMouse()
{
	HRESULT result = m_mouse->GetDeviceState(sizeof(DIMOUSESTATE), (LPVOID)&m_mouse_state);

	if (result == DI_OK)		//Mouse�擾�ł�����True
	{
		return true;
	}

	//����Window�����C���Ȃǂ̏ꍇ�͎擾�����݂�
	if (result == DIERR_INPUTLOST || result == DIERR_NOTACQUIRED)
	{
		m_keyboard->Acquire();
		return true;
	}

	return false;			//���̑��̏ꍇ
}

//�O�t���[����Keyboard�X�V
void InputState::UpdateKeyboard()
{
	for (int i = 0; i < sizeof(m_current_keyboard_state); i++)
	{
		m_previous_keyboard_state[i] = m_current_keyboard_state[i];
	}
}

//�}�E�X�̈ʒu����ʓ���Clamp
void InputState::ClampMousePosition()
{
	m_mouse_x += m_mouse_state.lX;
	m_mouse_y += m_mouse_state.lY;

	if (m_mouse_x < 0)
		m_mouse_x = 0;
	if (m_mouse_y < 0)
		m_mouse_y = 0;

	if (m_mouse_x > WindowDef::kScreenWidth)
		m_mouse_x = WindowDef::kScreenWidth;
	if (m_mouse_y > WindowDef::kScreenHeight)
		m_mouse_y = WindowDef::kScreenHeight;
}

//�}�E�X�̈ʒu
void InputState::MousePosition(int& mouse_x, int& mouse_y)
{
	mouse_x = m_mouse_x;
	mouse_y = m_mouse_y;
}

//�w��̃L�[��������Ă��邩
bool InputState::IsKeyDown(unsigned int dik_key)
{
	return (m_current_keyboard_state[dik_key] & 0x80) != 0;
}

//�w��̃L�[�����̃t���[���ŉ�����Ă��邩
bool InputState::IsKeyTrigger(unsigned int dik_key)
{
	return (m_previous_keyboard_state[dik_key] & 0x80) == 0 && IsKeyDown(dik_key);
}